#ifndef SERVO_MOTOR_CONSTRAINTS_DELTA_U_MIN_HPP_
#define SERVO_MOTOR_CONSTRAINTS_DELTA_U_MIN_HPP_

#include "python_numpy.hpp"

namespace servo_motor_constraints_delta_U_min {

using namespace PythonNumpy;

using type = DenseMatrix_Type<float, 1, 1>;

inline auto make(void) -> type {

  return make_DenseMatrix<1, 1>(static_cast<float>(1.0));
}

} // namespace servo_motor_constraints_delta_U_min

#endif // SERVO_MOTOR_CONSTRAINTS_DELTA_U_MIN_HPP_
