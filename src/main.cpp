#define USE_EIGEN_LIBRARY (1)

#include "main.hpp"

void setup() {
  /* calculation */

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
