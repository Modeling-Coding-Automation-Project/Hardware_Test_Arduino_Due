#ifndef __SERVO_MOTOR_CONSTRAINTS_Y_MAX_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_Y_MAX_HPP__

#include "python_numpy.hpp"

namespace servo_motor_constraints_Y_max {

using namespace PythonNumpy;

using SparseAvailable_Y_max =
    SparseAvailable<ColumnAvailable<false>, ColumnAvailable<false>>;

using type = SparseMatrix_Type<float, SparseAvailable_Y_max>;

inline auto make(void) -> type { return make_SparseMatrixEmpty<float, 2, 1>(); }

} // namespace servo_motor_constraints_Y_max

#endif // __SERVO_MOTOR_CONSTRAINTS_Y_MAX_HPP__
