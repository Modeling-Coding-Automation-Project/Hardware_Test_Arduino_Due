#ifndef __SERVO_MOTOR_LTI_MPC_LKF_SS_C_HPP__
#define __SERVO_MOTOR_LTI_MPC_LKF_SS_C_HPP__

#include "python_numpy.hpp"

namespace servo_motor_lti_mpc_lkf_ss_C {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_lkf_ss_C =
    SparseAvailable<ColumnAvailable<true, false, false, false>,
                    ColumnAvailable<true, false, true, false>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_lkf_ss_C>;

inline auto make(void) -> type {

  return make_SparseMatrix<SparseAvailable_lti_mpc_lkf_ss_C>(
      static_cast<float>(1.0), static_cast<float>(1280.1990063378407),
      static_cast<float>(-64.00995031689203));
}

} // namespace servo_motor_lti_mpc_lkf_ss_C

#endif // __SERVO_MOTOR_LTI_MPC_LKF_SS_C_HPP__
