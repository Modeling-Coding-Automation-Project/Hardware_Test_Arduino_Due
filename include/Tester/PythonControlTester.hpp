#ifndef __PYTHON_CONTROL_TESTER_HPP__
#define __PYTHON_CONTROL_TESTER_HPP__

#define USE_EIGEN_LIBRARY (0)

#include "python_control.hpp"

#include <cmath>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdint.h>

#include <Arduino.h>

class PythonControlTester {
public:
  /* Constant, Type */
  static constexpr std::size_t LS_NUMBER_OF_DATA = 20;
  static constexpr std::size_t X_SIZE = 2;
  static constexpr std::size_t Y_SIZE = 1;

  using LS_X_Type =
      PythonNumpy::DenseMatrix_Type<float, LS_NUMBER_OF_DATA, X_SIZE>;
  using LS_Y_Type =
      PythonNumpy::DenseMatrix_Type<float, LS_NUMBER_OF_DATA, Y_SIZE>;

  using LS_Type = PythonControl::LeastSquares_Type<LS_X_Type>;

public:
  /* Constructor */
  PythonControlTester();

  /* Destructor */
  ~PythonControlTester();

public:
  /* Functions */
  void test_ls(void);

private:
  /* Variables */
  LS_Type ls;
  LS_X_Type LS_X;
  LS_Y_Type LS_Y;
};

#endif // __PYTHON_CONTROL_TESTER_HPP__
