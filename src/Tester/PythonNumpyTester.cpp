#include "PythonNumpyTester.hpp"

PythonNumpyTester::PythonNumpyTester()
#if USE_EIGEN_LIBRARY == 1

    : C(4, 4) // SparseMatrixの初期化

#else // USE_EIGEN_LIBRARY == 0

    : A({{2, 3, 1, 5}, {4, 1, 6, 2}, {0, 7, 3, 8}, {9, 5, 2, 4}}),
      C({5, 7, 4, 3, 2, 8})

#endif
{
#if USE_EIGEN_LIBRARY == 1
  A << 2, 3, 1, 5, 4, 1, 6, 2, 0, 7, 3, 8, 9, 5, 2, 4;

  C.insert(0, 2) = 5;
  C.insert(1, 0) = 7;
  C.insert(2, 0) = 4;
  C.insert(2, 3) = 3;
  C.insert(3, 0) = 2;
  C.insert(3, 2) = 8;
  C.makeCompressed();

#else  // USE_EIGEN_LIBRARY == 0
#endif // USE_EIGEN_LIBRARY == 1
}

void PythonNumpyTester::test_arithmetic_operation(void) {
  unsigned long time_start = 0;
  unsigned long time_end = 0;

  time_start = micros(); // start measuring.

#if USE_EIGEN_LIBRARY == 1

  Eigen::Matrix<float, 4, 4> D = C * A;

#else // USE_EIGEN_LIBRARY == 0

  auto D = C * A;

#endif // USE_EIGEN_LIBRARY == 1

  time_end = micros(); // end measuring.

  /* send result */
  Serial.begin(9600);

  Serial.println("Result = ");
  std::stringstream result_stream;
  for (std::size_t i = 0; i < D.cols(); i++) {
    for (std::size_t j = 0; j < D.rows(); j++) {

#if USE_EIGEN_LIBRARY == 1
      result_stream << D(i, j) << " ";
#else
      result_stream << D.matrix(i, j) << " ";
#endif
    }
    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());

  Serial.print("Calculation time[us]: ");
  Serial.println(time_end - time_start);
}

PythonNumpyTester::~PythonNumpyTester() {}
