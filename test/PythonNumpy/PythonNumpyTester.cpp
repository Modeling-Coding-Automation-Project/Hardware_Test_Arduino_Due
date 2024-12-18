#include "PythonNumpyTester.hpp"

PythonNumpyTester::PythonNumpyTester()
#if USE_EIGEN_LIBRARY == 1
    : C(4, 4) // SparseMatrixの初期化
#endif
{
}