#ifndef __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_B_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_B_HPP__

#include "python_numpy.hpp"

namespace servo_motor_constraints_lti_mpc_lkf_ss_B {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_lkf_ss_B =
    SparseAvailable<ColumnAvailable<false>, ColumnAvailable<false>,
                    ColumnAvailable<false>, ColumnAvailable<true>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_lkf_ss_B>;

inline auto make(void) -> type {

  return make_SparseMatrix<SparseAvailable_lti_mpc_lkf_ss_B>(
      static_cast<float>(0.04999999999999999));
}

} // namespace servo_motor_constraints_lti_mpc_lkf_ss_B

#endif // __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_B_HPP__
