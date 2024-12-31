#include "PythonMathTester.hpp"

const double PythonMathTester::INPUT_DATA_2_I[ARRAY_SIZE] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18};

const double PythonMathTester::INPUT_DATA_EXP_2_I[ARRAY_SIZE] = {
    1.0,
    7.38905609893065,
    54.598150033144236,
    403.4287934927351,
    2980.9579870417283,
    22026.465794806718,
    162754.79141900392,
    1202604.2841647768,
    8886110.520507872,
    65659969.13733051};

const double PythonMathTester::INPUT_DATA_EXP_2_I_SQRT[ARRAY_SIZE] = {
    1.0,
    2.718281828459045,
    7.38905609893065,
    20.085536923187668,
    54.598150033144236,
    148.4131591025766,
    403.4287934927351,
    1096.6331584284585,
    2980.9579870417283,
    8103.083927575384};

const double PythonMathTester::INPUT_DATA_10_I[ARRAY_SIZE] = {
    0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

const double PythonMathTester::INPUT_DATA_10_I_SIN[ARRAY_SIZE] = {
    0.0,
    -0.5440211108893698,
    0.9129452507276277,
    -0.9880316240928618,
    0.7451131604793488,
    -0.26237485370392877,
    -0.3048106211022167,
    0.7738906815578891,
    -0.9938886539233752,
    0.8939966636005579};

const double PythonMathTester::INPUT_DATA_10_I_COS[ARRAY_SIZE] = {
    1.0,
    -0.8390715290764524,
    0.40808206181339196,
    0.15425144988758405,
    -0.6669380616522619,
    0.9649660284921133,
    -0.9524129804151563,
    0.6333192030862999,
    -0.11038724383904756,
    -0.4480736161291701};

const double PythonMathTester::INPUT_DATA_10_I_ATAN[ARRAY_SIZE] = {
    0.0000000000000000, 1.4711276743037347, 1.5208379310729538,
    1.5374753309166493, 1.5458015331759765, 1.5507989928217460,
    1.5541312030809560, 1.5565115842074999, 1.5582969777755349,
    1.5596856728972892};

const double PythonMathTester::ASIN_FROM_INPUT_DATA_10_I_SIN[ARRAY_SIZE] = {
    0.0,
    -0.5752220392306202,
    1.1504440784612406,
    -1.4159265358979325,
    0.8407044966673122,
    -0.2654824574366918,
    -0.30973958179392846,
    0.8849616210245488,
    -1.4601836602551694,
    1.106186954104004};

PythonMathTester::PythonMathTester() : y_array({}) {}

void PythonMathTester::test_sqrt(void) {
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<FLOAT>(PythonMathTester::INPUT_DATA_EXP_2_I[i]);
    y_array_answer[i] =
        static_cast<FLOAT>(PythonMathTester::INPUT_DATA_EXP_2_I_SQRT[i]);
  }

  unsigned long time_start[PythonMathTester::ARRAY_SIZE] = {0};
  unsigned long time_end[PythonMathTester::ARRAY_SIZE] = {0};

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {

    time_start[i] = micros(); // start measuring.

    // y_array[i] = std::sqrt(x_array[i]);
    y_array[i] = PythonMath::sqrt(x_array[i]);

    time_end[i] = micros(); // end measuring.
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  if (4 == sizeof(FLOAT)) {
    result_stream << std::scientific << std::setprecision(7);
  } else {
    result_stream << std::scientific << std::setprecision(16);
  }

  result_stream << "Input, Output, dif, Calculation time[us]" << std::endl;
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    result_stream << x_array[i] << ", ";
    result_stream << y_array[i] << ", ";
    result_stream << y_array[i] - y_array_answer[i] << ", ";
    result_stream << time_end[i] - time_start[i];

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}

void PythonMathTester::test_exp(void) {
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<FLOAT>(PythonMathTester::INPUT_DATA_2_I[i]);
    y_array_answer[i] =
        static_cast<FLOAT>(PythonMathTester::INPUT_DATA_EXP_2_I[i]);
  }

  unsigned long time_start[PythonMathTester::ARRAY_SIZE] = {0};
  unsigned long time_end[PythonMathTester::ARRAY_SIZE] = {0};

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {

    time_start[i] = micros(); // start measuring.

    // y_array[i] = std::exp(x_array[i]);
    // y_array[i] = PythonMath::exp(x_array[i]);
    y_array[i] =
        Base::Math::exp_maclaurin_expansion_with_table<FLOAT, 4>(x_array[i]);

    time_end[i] = micros(); // end measuring.
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  if (4 == sizeof(FLOAT)) {
    result_stream << std::scientific << std::setprecision(7);
  } else {
    result_stream << std::scientific << std::setprecision(16);
  }

  result_stream << "Input, Output, dif, Calculation time[us]" << std::endl;
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    result_stream << x_array[i] << ", ";
    result_stream << y_array[i] << ", ";
    result_stream << y_array[i] - y_array_answer[i] << ", ";
    result_stream << time_end[i] - time_start[i];

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}

void PythonMathTester::test_log(void) {
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<FLOAT>(PythonMathTester::INPUT_DATA_EXP_2_I[i]);
    y_array_answer[i] = static_cast<FLOAT>(PythonMathTester::INPUT_DATA_2_I[i]);
  }

  unsigned long time_start[PythonMathTester::ARRAY_SIZE] = {0};
  unsigned long time_end[PythonMathTester::ARRAY_SIZE] = {0};

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {

    time_start[i] = micros(); // start measuring.

    // y_array[i] = std::log(x_array[i]);
    // y_array[i] = PythonMath::log(x_array[i]);
    y_array[i] =
        Base::Math::log_maclaurin_expansion_with_table<FLOAT>(x_array[i]);

    time_end[i] = micros(); // end measuring.
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  if (4 == sizeof(FLOAT)) {
    result_stream << std::scientific << std::setprecision(7);
  } else {
    result_stream << std::scientific << std::setprecision(16);
  }

  result_stream << "Input, Output, dif, Calculation time[us]" << std::endl;
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    result_stream << x_array[i] << ", ";
    result_stream << y_array[i] << ", ";
    result_stream << y_array[i] - y_array_answer[i] << ", ";
    result_stream << time_end[i] - time_start[i];

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}

void PythonMathTester::test_trigonometric(void) {
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I[i]);
    // x_array[i] =
    // static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I_SIN[i]);

    // y_array_answer[i] =
    //     static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I_SIN[i]);
    // y_array_answer[i] =
    //     static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I_COS[i]);
    y_array_answer[i] =
        static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I_ATAN[i]);
    // y_array_answer[i] =
    //     static_cast<FLOAT>(PythonMathTester::ASIN_FROM_INPUT_DATA_10_I_SIN[i]);
  }

  unsigned long time_start[PythonMathTester::ARRAY_SIZE] = {0};
  unsigned long time_end[PythonMathTester::ARRAY_SIZE] = {0};

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {

    time_start[i] = micros(); // start measuring.

    // y_array[i] = std::cos(x_array[i]);
    // y_array[i] = PythonMath::sin(x_array[i]);
    // y_array[i] =
    //     Base::Math::cos_maclaurin_expansion_with_DoubleAngleFormula<FLOAT,
    //     3>(
    //         x_array[i]);

    // y_array[i] = std::atan(x_array[i]);
    y_array[i] = Base::Math::atan(x_array[i]);

    // y_array[i] = std::asin(x_array[i]);
    // y_array[i] = Base::Math::asin(x_array[i]);

    time_end[i] = micros(); // end measuring.
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  if (4 == sizeof(FLOAT)) {
    result_stream << std::scientific << std::setprecision(7);
  } else {
    result_stream << std::scientific << std::setprecision(16);
  }

  result_stream << "Input, Output, dif, Calculation time[us]" << std::endl;
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    result_stream << x_array[i] << ", ";
    result_stream << y_array[i] << ", ";
    result_stream << y_array[i] - y_array_answer[i] << ", ";
    result_stream << time_end[i] - time_start[i];

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}

void PythonMathTester::test_sincos(void) {
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I[i]);
    y_array_answer[i] =
        static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I_SIN[i]);
    y_array_answer_2[i] =
        static_cast<FLOAT>(PythonMathTester::INPUT_DATA_10_I_COS[i]);
  }

  unsigned long time_start[PythonMathTester::ARRAY_SIZE] = {0};
  unsigned long time_end[PythonMathTester::ARRAY_SIZE] = {0};

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {

    time_start[i] = micros(); // start measuring.

    // y_array[i] = std::sin(x_array[i]);
    // y_array_2[i] = std::cos(x_array[i]);

    Base::Math::sincos_maclaurin_expansion_with_DoubleAngleFormula<FLOAT, 3>(
        x_array[i], y_array_2[i], y_array[i]);

    time_end[i] = micros(); // end measuring.
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  if (4 == sizeof(FLOAT)) {
    result_stream << std::scientific << std::setprecision(7);
  } else {
    result_stream << std::scientific << std::setprecision(16);
  }

  result_stream << "Input, Sin, Sin dif, Cos, Cos dif, Calculation time[us]"
                << std::endl;
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    result_stream << x_array[i] << ", ";
    result_stream << y_array[i] << ", ";
    result_stream << y_array[i] - y_array_answer[i] << ", ";
    result_stream << y_array_2[i] << ", ";
    result_stream << y_array_2[i] - y_array_answer_2[i] << ", ";
    result_stream << time_end[i] - time_start[i];

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}

PythonMathTester::~PythonMathTester() {}
