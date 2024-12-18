#ifndef PYTHON_MATH_TESTER_HPP
#define PYTHON_MATH_TESTER_HPP

#include "python_math.hpp"

#include <cmath>
#include <cstring>
#include <sstream>
#include <stdint.h>

#include <Arduino.h>

class PythonMathTester {
public:
  /* Constructor */
  PythonMathTester();

  /* Destructor */
  ~PythonMathTester();

public:
  /* Constant */
  static constexpr std::size_t ARRAY_SIZE = 10;

private:
  /* Variables */
  std::array<float, ARRAY_SIZE> x_array;
  std::array<float, ARRAY_SIZE> y_array;

public:
  /* Functions */
  void test_sqrt(void);
};

#endif // PYTHON_MATH_TESTER_HPP
