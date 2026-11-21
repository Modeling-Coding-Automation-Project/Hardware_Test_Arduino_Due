#ifndef SERVO_MOTOR_LTI_MPC_LKF_SS_C_HPP_
#define SERVO_MOTOR_LTI_MPC_LKF_SS_C_HPP_

#include "python_numpy.hpp"

namespace servo_motor_lti_mpc_lkf_ss_C {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_lkf_ss_C =
    SparseAvailable<ColumnAvailable<true, false, false, false>,
                    ColumnAvailable<true, false, true, false>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_lkf_ss_C>;

inline auto make(void) -> type {

  auto result =
      make_SparseMatrixZeros<float, SparseAvailable_lti_mpc_lkf_ss_C>();

  result.unsafe_access(0) = static_cast<float>(1.0);
  result.unsafe_access(1) = static_cast<float>(1280.1990063378407);
  result.unsafe_access(2) = static_cast<float>(-64.00995031689203);

  return result;
}

} // namespace servo_motor_lti_mpc_lkf_ss_C

#endif // SERVO_MOTOR_LTI_MPC_LKF_SS_C_HPP_
