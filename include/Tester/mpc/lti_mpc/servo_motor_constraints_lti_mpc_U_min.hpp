#ifndef SERVO_MOTOR_CONSTRAINTS_LTI_MPC_U_MIN_HPP_
#define SERVO_MOTOR_CONSTRAINTS_LTI_MPC_U_MIN_HPP_

#include "python_numpy.hpp"

namespace servo_motor_constraints_lti_mpc_U_min {

using namespace PythonNumpy;

using type = DenseMatrix_Type<float, 1, 1>;

inline auto make(void) -> type {

  auto result = make_DenseMatrixZeros<float, 1, 1>();

  result.unsafe_access(0, 0) = static_cast<float>(1.0);

  return result;
}

} // namespace servo_motor_constraints_lti_mpc_U_min

#endif // SERVO_MOTOR_CONSTRAINTS_LTI_MPC_U_MIN_HPP_
