#include "PythonMathTester.hpp"

PythonMathTester::PythonMathTester() : y_array({}) {

  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    x_array[i] = static_cast<float>(i);
  }
}

void PythonMathTester::test_sqrt(void) {
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

  result_stream << "Input, Output, Calculation time[us]" << std::endl;
  for (std::size_t i = 0; i < PythonMathTester::ARRAY_SIZE; i++) {
    result_stream << x_array[i] << " ";
    result_stream << y_array[i] << " ";
    result_stream << time_end - time_start;

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}

PythonMathTester::~PythonMathTester() {}
