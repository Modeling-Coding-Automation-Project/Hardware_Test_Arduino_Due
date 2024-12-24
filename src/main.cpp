#include "main.hpp"

void setup() {
  /* calculation */
  // python_numpy_tester.test_arithmetic_operation();
  // base_utility_tester.test_copy();
  python_math_tester.test_sincos();

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
