#ifndef __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_A_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_A_HPP__

#include "python_numpy.hpp"

namespace servo_motor_constraints_lti_mpc_lkf_ss_A {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_lkf_ss_A =
    SparseAvailable<ColumnAvailable<true, true, false, false>,
                    ColumnAvailable<true, true, true, false>,
                    ColumnAvailable<false, false, true, true>,
                    ColumnAvailable<true, false, true, true>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_lkf_ss_A>;

inline auto make(void) -> type {

  return make_SparseMatrix<SparseAvailable_lti_mpc_lkf_ss_A>(
      static_cast<float>(1.0), static_cast<float>(0.05),
      static_cast<float>(-2.5603853840856576),
      static_cast<float>(0.9500002466138069),
      static_cast<float>(0.12801926920428286), static_cast<float>(1.0),
      static_cast<float>(0.05), static_cast<float>(6.400995031689203),
      static_cast<float>(-0.3200497515844601),
      static_cast<float>(0.4900000000000001));
}

} // namespace servo_motor_constraints_lti_mpc_lkf_ss_A

#endif // __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_SS_A_HPP__
