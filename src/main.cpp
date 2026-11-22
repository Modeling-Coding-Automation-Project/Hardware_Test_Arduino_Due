#ifdef HARDWARE_TEST_BASE_UTILITY_COPY
#include "BaseUtilityTester.hpp"
static BaseUtilityTester base_utility_tester;
#elif defined(HARDWARE_TEST_MATH_SQRT) || defined(HARDWARE_TEST_MATH_EXP) ||   \
    defined(HARDWARE_TEST_MATH_LOG) ||                                         \
    defined(HARDWARE_TEST_MATH_TRIGONOMETRIC) ||                               \
    defined(HARDWARE_TEST_MATH_SINCOS)
#include "PythonMathTester.hpp"
static PythonMathTester python_math_tester;
#elif defined(HARDWARE_TEST_NUMPY_ARITHMETIC)
#include "PythonNumpyTester.hpp"
static PythonNumpyTester python_numpy_tester;
#elif defined(HARDWARE_TEST_NUMPY_LINALG)
#include "PythonNumpyLinalgTester.hpp"
static PythonNumpyLinalgTester python_numpy_linalg_tester;
#elif defined(HARDWARE_TEST_CONTROL_LS) || defined(HARDWARE_TEST_CONTROL_RLS)
#include "PythonControlTester.hpp"
static PythonControlTester python_control_tester;
#elif defined(HARDWARE_TEST_LTI_MPC)
#include "PythonMPC_Tester.hpp"
static PythonMPC_Tester python_mpc_tester;
#else
#error "Select a hardware test in platformio.ini."
#endif

#include "main.hpp"

void setup() {
#ifdef HARDWARE_TEST_BASE_UTILITY_COPY
  base_utility_tester.test_copy();
#elif defined(HARDWARE_TEST_MATH_SQRT)
  python_math_tester.test_sqrt();
#elif defined(HARDWARE_TEST_MATH_EXP)
  python_math_tester.test_exp();
#elif defined(HARDWARE_TEST_MATH_LOG)
  python_math_tester.test_log();
#elif defined(HARDWARE_TEST_MATH_TRIGONOMETRIC)
  python_math_tester.test_trigonometric();
#elif defined(HARDWARE_TEST_MATH_SINCOS)
  python_math_tester.test_sincos();
#elif defined(HARDWARE_TEST_NUMPY_ARITHMETIC)
  python_numpy_tester.test_arithmetic_operation();
#elif defined(HARDWARE_TEST_NUMPY_LINALG)
  python_numpy_linalg_tester.test_linalg();
#elif defined(HARDWARE_TEST_CONTROL_LS)
  python_control_tester.test_ls();
#elif defined(HARDWARE_TEST_CONTROL_RLS)
  python_control_tester.test_rls();
#elif defined(HARDWARE_TEST_LTI_MPC)
  python_mpc_tester.test_mpc();
#endif

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
