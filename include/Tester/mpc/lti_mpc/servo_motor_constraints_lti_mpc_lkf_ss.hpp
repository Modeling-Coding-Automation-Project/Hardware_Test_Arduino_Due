#ifndef __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_HPP__

#include "servo_motor_constraints_lti_mpc_lkf_ss_A.hpp"
#include "servo_motor_constraints_lti_mpc_lkf_ss_B.hpp"
#include "servo_motor_constraints_lti_mpc_lkf_ss_C.hpp"
#include "servo_motor_constraints_lti_mpc_lkf_ss_D.hpp"

#include "python_control.hpp"

namespace servo_motor_constraints_lti_mpc_lkf_ss {

using namespace PythonControl;

constexpr std::size_t NUMBER_OF_DELAY = 0;

using A_Type = servo_motor_constraints_lti_mpc_lkf_ss_A::type;

using B_Type = servo_motor_constraints_lti_mpc_lkf_ss_B::type;

using C_Type = servo_motor_constraints_lti_mpc_lkf_ss_C::type;

using D_Type = servo_motor_constraints_lti_mpc_lkf_ss_D::type;

constexpr std::size_t INPUT_SIZE = B_Type::ROWS;
constexpr std::size_t STATE_SIZE = A_Type::COLS;
constexpr std::size_t OUTPUT_SIZE = C_Type::COLS;

using type =
    DiscreteStateSpace_Type<A_Type, B_Type, C_Type, D_Type, NUMBER_OF_DELAY>;

inline auto make(void) -> type {

  float dt = static_cast<float>(1.0);

  auto A = servo_motor_constraints_lti_mpc_lkf_ss_A::make();

  auto B = servo_motor_constraints_lti_mpc_lkf_ss_B::make();

  auto C = servo_motor_constraints_lti_mpc_lkf_ss_C::make();

  auto D = servo_motor_constraints_lti_mpc_lkf_ss_D::make();

  return make_DiscreteStateSpace<NUMBER_OF_DELAY>(A, B, C, D, dt);
}

} // namespace servo_motor_constraints_lti_mpc_lkf_ss

#endif // __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_HPP__
