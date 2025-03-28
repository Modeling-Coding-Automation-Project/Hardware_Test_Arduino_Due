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

namespace LS_TestData {

constexpr std::size_t NUMBER_OF_DATA = 100;
constexpr std::size_t X_SIZE = 2;
constexpr std::size_t Y_SIZE = 1;

double get_test_X(std::size_t i, std::size_t j);

double get_test_Y(std::size_t i, std::size_t j);

} // namespace LS_TestData

class PythonControlTester {
public:
  /* Constant, Type */
  static constexpr std::size_t LS_NUMBER_OF_DATA = 20;
  static constexpr std::size_t RLS_NUMBER_OF_DATA = 100;
  static constexpr std::size_t X_SIZE = 2;
  static constexpr std::size_t Y_SIZE = 1;

  using LS_X_Type =
      PythonNumpy::DenseMatrix_Type<float, LS_NUMBER_OF_DATA, X_SIZE>;
  using LS_Y_Type =
      PythonNumpy::DenseMatrix_Type<float, LS_NUMBER_OF_DATA, Y_SIZE>;
  using LS_Type = PythonControl::LeastSquares_Type<LS_X_Type>;

  using RLS_X_Type = PythonControl::StateSpaceStateType<float, X_SIZE>;
  using RLS_Type = PythonControl::RecursiveLeastSquares_Type<RLS_X_Type>;

public:
  /* Constructor */
  PythonControlTester();

  /* Destructor */
  ~PythonControlTester();

public:
  /* Functions */
  void test_ls(void);
  void test_rls(void);

private:
  /* Variables */
  LS_Type ls;
  RLS_Type rls;

  LS_X_Type LS_X;
  LS_Y_Type LS_Y;
};

#endif // __PYTHON_CONTROL_TESTER_HPP__
