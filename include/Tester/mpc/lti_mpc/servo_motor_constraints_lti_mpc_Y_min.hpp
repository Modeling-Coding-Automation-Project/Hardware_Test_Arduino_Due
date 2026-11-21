#ifndef SERVO_MOTOR_CONSTRAINTS_LTI_MPC_Y_MIN_HPP_
#define SERVO_MOTOR_CONSTRAINTS_LTI_MPC_Y_MIN_HPP_

#include "python_numpy.hpp"

namespace servo_motor_constraints_lti_mpc_Y_min {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_Y_min =
    SparseAvailable<ColumnAvailable<false>, ColumnAvailable<false>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_Y_min>;

inline auto make(void) -> type { return make_SparseMatrixEmpty<float, 2, 1>(); }

} // namespace servo_motor_constraints_lti_mpc_Y_min

#endif // SERVO_MOTOR_CONSTRAINTS_LTI_MPC_Y_MIN_HPP_
