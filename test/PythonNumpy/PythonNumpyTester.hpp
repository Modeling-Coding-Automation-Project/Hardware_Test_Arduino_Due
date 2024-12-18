#ifndef PYTHON_NUMPY_TESTER_HPP
#define PYTHON_NUMPY_TESTER_HPP

#define USE_EIGEN_LIBRARY (1)

#if USE_EIGEN_LIBRARY == 1
#include "Core"   // Eigen library
#include "Sparse" // Eigen library
#else
#include "python_numpy.hpp"
#endif

class PythonNumpyTester {
public:
  /* Constructor */
  PythonNumpyTester();

  /* Variables */
private:
#if USE_EIGEN_LIBRARY == 1

  Eigen::Matrix<float, 4, 4> A;
  Eigen::SparseMatrix<float> C;

#else  // USE_EIGEN_LIBRARY == 0
#endif // USE_EIGEN_LIBRARY == 1

  /* Destructor */
  ~PythonNumpyTester();
};

#endif // PYTHON_NUMPY_TESTER_HPP
