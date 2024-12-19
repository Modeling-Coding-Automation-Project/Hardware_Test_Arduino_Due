#ifndef PYTHON_MATH_TESTER_HPP
#define PYTHON_MATH_TESTER_HPP

#include "python_math.hpp"

#include <cmath>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdint.h>

#include <Arduino.h>

// typedef float FLOAT;
typedef double FLOAT;

class PythonMathTester {
public:
  /* Constructor */
  PythonMathTester();

  /* Destructor */
  ~PythonMathTester();

public:
  /* Constant */
  static constexpr std::size_t ARRAY_SIZE = 10;
  static const double INPUT_DATA_2_I[ARRAY_SIZE];
  static const double INPUT_DATA_EXP_2_I[ARRAY_SIZE];
  static const double INPUT_DATA_EXP_2_I_SQRT[ARRAY_SIZE];

private:
  /* Variables */
  std::array<FLOAT, ARRAY_SIZE> x_array;
  std::array<FLOAT, ARRAY_SIZE> y_array;
  std::array<FLOAT, ARRAY_SIZE> y_array_answer;

public:
  /* Functions */
  void test_sqrt(void);
  void test_exp(void);
};

#endif // PYTHON_MATH_TESTER_HPP
