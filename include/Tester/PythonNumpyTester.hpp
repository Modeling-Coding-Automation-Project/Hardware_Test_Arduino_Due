#ifndef PYTHON_NUMPY_TESTER_HPP
#define PYTHON_NUMPY_TESTER_HPP

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

  PythonNumpy::Matrix<PythonNumpy::DefDense, float, 4, 4> A;
  PythonNumpy::Matrix<
      PythonNumpy::DefSparse, float, 4, 4,
      PythonNumpy::SparseAvailable<
          PythonNumpy::ColumnAvailable<false, false, true, false>,
          PythonNumpy::ColumnAvailable<true, false, false, false>,
          PythonNumpy::ColumnAvailable<true, false, false, true>,
          PythonNumpy::ColumnAvailable<true, false, true, false>>>
      C;

#endif // USE_EIGEN_LIBRARY == 1
};

#endif // PYTHON_NUMPY_TESTER_HPP
