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
  static constexpr std::size_t INPUT_SIZE =
      servo_motor_constraints_lti_mpc::INPUT_SIZE;
  static constexpr std::size_t STATE_SIZE =
      servo_motor_constraints_lti_mpc::STATE_SIZE;
  static constexpr std::size_t OUTPUT_SIZE =
      servo_motor_constraints_lti_mpc::OUTPUT_SIZE;

  using Tester_MPC_Type = servo_motor_constraints_lti_mpc::type;

public:
  /* Constructor */
  PythonMPC_Tester();

  /* Destructor */
  ~PythonMPC_Tester();

public:
  /* Functions */
  void test_mpc(void);

private:
  /* Variables */
  Tester_MPC_Type _mpc;
};

#endif // __PYTHON_MPC_TESTER_HPP__
