#include "PythonMathTester.hpp"

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

PythonMathTester::PythonMathTester() : y_array({}) {

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<float>(PythonMathTester::INPUT_DATA_EXP_2_I[i]);
    y_array_answer[i] =
        static_cast<float>(PythonMathTester::INPUT_DATA_EXP_2_I_SQRT[i]);
  }
}

void PythonMathTester::test_sqrt(void) {
  unsigned long time_start[PythonMathTester::ARRAY_SIZE] = {0};
  unsigned long time_end[PythonMathTester::ARRAY_SIZE] = {0};

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {

    time_start[i] = micros(); // start measuring.

    y_array[i] = std::sqrt(x_array[i]);
    // y_array[i] = PythonMath::sqrt(x_array[i]);

    time_end[i] = micros(); // end measuring.
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  result_stream << std::scientific << std::setprecision(7);

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

PythonMathTester::~PythonMathTester() {}
