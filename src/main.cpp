#define USE_EIGEN_LIBRARY (0)

#if USE_EIGEN_LIBRARY == 1
#include "Core"   // Eigen library
#include "Sparse" // Eigen library
#else
#include "python_numpy.hpp"
#endif

#include "main.hpp"

void setup() {
/* prepare calculation */
#if USE_EIGEN_LIBRARY == 1
  Eigen::Matrix<float, 4, 4> A;
  A << 2, 3, 1, 5, 4, 1, 6, 2, 0, 7, 3, 8, 9, 5, 2, 4;

  Eigen::SparseMatrix<float> C(4, 4);
  C.insert(0, 2) = 5;
  C.insert(1, 0) = 7;
  C.insert(2, 0) = 4;
  C.insert(2, 3) = 3;
  C.insert(3, 0) = 2;
  C.insert(3, 2) = 8;
  C.makeCompressed();

#else
  PythonNumpy::Matrix<PythonNumpy::DefDense, float, 4, 4> A(
      {{2, 3, 1, 5}, {4, 1, 6, 2}, {0, 7, 3, 8}, {9, 5, 2, 4}});
  PythonNumpy::Matrix<
      PythonNumpy::DefSparse, float, 4, 4,
      PythonNumpy::SparseAvailable<
          PythonNumpy::ColumnAvailable<false, false, true, false>,
          PythonNumpy::ColumnAvailable<true, false, false, false>,
          PythonNumpy::ColumnAvailable<true, false, false, true>,
          PythonNumpy::ColumnAvailable<true, false, true, false>>>
      C({5, 7, 4, 3, 2, 8});

#endif

  unsigned long time_start = 0;
  unsigned long time_end = 0;

  /* calculation */
  time_start = micros(); // start measuring.

#if USE_EIGEN_LIBRARY == 1
  Eigen::Matrix<float, 4, 4> D = C * A;
#else
  auto D = C * A;
#endif

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

  /* Timer interrupt preset */
  pinMode(LED_BUILTIN, OUTPUT);
  TimeManager::start_timer(TC1, 0, TC3_IRQn,
                           TimeManager::SAMPLING_TIME_STEP_MSEC);

  pinMode(SS0PIN, OUTPUT);
  digitalWrite(SS0PIN, HIGH);
}

void loop() {}

void TC3_Handler() {
  TC_GetStatus(TC1, 0);

  double now_time = TimeManager::get_time();

  if (((int)now_time % 2) == 1) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }

  /* Count up time */
  TimeManager::count_time();
}
