#include "time_manager.hpp"

const double TimeManager::MSEC_TO_SEC = 0.001;
const int TimeManager::SAMPLING_TIME_STEP_MSEC = 5;
double TimeManager::_now_time = 0.0;

void TimeManager::start_timer(Tc *tc, uint32_t channel, IRQn_Type irq_type,
                              uint32_t sampling_time_step_msec) {
  pmc_enable_periph_clk((uint32_t)irq_type);
  TC_Configure(tc, channel,
               TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK1);
  uint32_t rc = (VARIANT_MCK / 2 / 1000) * sampling_time_step_msec;
  TC_SetRC(tc, channel, rc);
  TC_Start(tc, channel);
  tc->TC_CHANNEL[channel].TC_IER = TC_IER_CPCS;
  tc->TC_CHANNEL[channel].TC_IDR = ~TC_IER_CPCS;
  NVIC_EnableIRQ(irq_type);
}

void TimeManager::count_time(void) {
  _now_time += (double)SAMPLING_TIME_STEP_MSEC * MSEC_TO_SEC;
}

double TimeManager::get_time(void) { return _now_time; }
