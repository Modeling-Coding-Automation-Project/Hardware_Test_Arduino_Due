#ifndef __PYTHON_NUMPY_TESTER_HPP__
#define __PYTHON_NUMPY_TESTER_HPP__

#define USE_EIGEN_LIBRARY (0)

#if USE_EIGEN_LIBRARY == 1
#include "Core"   // Eigen library
#include "Sparse" // Eigen library
#else
#include "python_numpy.hpp"
#endif

#include <sstream>
#include <stdint.h>
#include <string>

#include <Arduino.h>

class PythonNumpyTester {
public:
  /* Constructor */
  PythonNumpyTester();

  /* Destructor */
  ~PythonNumpyTester();

public:
  /* Functions */
  void test_arithmetic_operation(void);

  /* Variables */
private:
#if USE_EIGEN_LIBRARY == 1

  Eigen::Matrix<float, 4, 4> A;
  Eigen::SparseMatrix<float> C;

#else // USE_EIGEN_LIBRARY == 0

  /* Type */
  using A_Type = decltype(PythonNumpy::make_DenseMatrix<4, 4>(0.0F));

  A_Type A;

  using C_Type =
      decltype(PythonNumpy::make_SparseMatrix<PythonNumpy::SparseAvailable<
                   PythonNumpy::ColumnAvailable<false, false, true, false>,
                   PythonNumpy::ColumnAvailable<true, false, false, false>,
                   PythonNumpy::ColumnAvailable<true, false, false, true>,
                   PythonNumpy::ColumnAvailable<true, false, true, false>>>(
          static_cast<float>(0)));

  C_Type C;

#endif // USE_EIGEN_LIBRARY == 1
};

#endif // __PYTHON_NUMPY_TESTER_HPP__
