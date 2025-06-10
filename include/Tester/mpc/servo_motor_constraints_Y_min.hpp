#ifndef __SERVO_MOTOR_CONSTRAINTS_Y_MIN_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_Y_MIN_HPP__

#include "python_numpy.hpp"

namespace servo_motor_constraints_Y_min {

using namespace PythonNumpy;

using SparseAvailable_Y_min = SparseAvailable<
    ColumnAvailable<false>,
    ColumnAvailable<false>
>;

using type = SparseMatrix_Type<double, SparseAvailable_Y_min>;

inline auto make(void) -> type {

  return make_SparseMatrixEmpty<double, 2, 1>();

}

} // namespace servo_motor_constraints_Y_min

#endif // __SERVO_MOTOR_CONSTRAINTS_Y_MIN_HPP__
