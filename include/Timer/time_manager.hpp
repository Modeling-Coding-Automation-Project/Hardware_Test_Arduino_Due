#ifndef _TIME_MANAGER_HPP_
#define _TIME_MANAGER_HPP_

#include <Arduino.h>
#include <stdint.h>

class TimeManager {
public:
  static const double MSEC_TO_SEC;
  static const int SAMPLING_TIME_STEP_MSEC;

private:
  static double _now_time;

public:
  static void start_timer(Tc *tc, uint32_t channel, IRQn_Type irq,
                          uint32_t mSec);
  static void count_time(void);
  static double get_time(void);
};

#endif
