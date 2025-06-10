#ifndef __PYTHON_MPC_TESTER_HPP__
#define __PYTHON_MPC_TESTER_HPP__

#include "python_mpc.hpp"
#include "servo_motor_constraints_lti_mpc.hpp"

#include <cmath>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdint.h>

#include <Arduino.h>

class PythonMPC_Tester {
public:
  /* Constant, Type */

public:
  /* Constructor */
  PythonMPC_Tester();

  /* Destructor */
  ~PythonMPC_Tester();
};

#endif // __PYTHON_MPC_TESTER_HPP__
