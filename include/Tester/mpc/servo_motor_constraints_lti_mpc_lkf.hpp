#ifndef __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_HPP__

#include "servo_motor_constraints_lti_mpc_lkf_ss.hpp"

#include "python_control.hpp"

namespace servo_motor_constraints_lti_mpc_lkf {

using namespace PythonNumpy;
using namespace PythonControl;

constexpr std::size_t NUMBER_OF_DELAY = 0;

using LkfStateSpace_Type = servo_motor_constraints_lti_mpc_lkf_ss::type;

constexpr std::size_t STATE_SIZE = LkfStateSpace_Type::A_Type::COLS;
constexpr std::size_t INPUT_SIZE = LkfStateSpace_Type::B_Type::ROWS;
constexpr std::size_t OUTPUT_SIZE = LkfStateSpace_Type::C_Type::COLS;

using Q_Type = KalmanFilter_Q_Type<double, STATE_SIZE>;

using R_Type = KalmanFilter_R_Type<double, OUTPUT_SIZE>;

using type = LinearKalmanFilter_Type<
    LkfStateSpace_Type, Q_Type, R_Type>;

auto make() -> type {

  auto lkf_state_space = servo_motor_constraints_lti_mpc_lkf_ss::make();

  auto Q = make_KalmanFilter_Q<STATE_SIZE>(
    static_cast<double>(1.0),
    static_cast<double>(1.0),
    static_cast<double>(1.0),
    static_cast<double>(1.0)
  );

  auto R = make_KalmanFilter_R<OUTPUT_SIZE>(
    static_cast<double>(1.0),
    static_cast<double>(1.0)
  );

  auto lkf = make_LinearKalmanFilter(
    lkf_state_space, Q, R);

  lkf.P = make_DenseMatrix<STATE_SIZE, STATE_SIZE>(
    static_cast<double>(0.0489392892491221),
    static_cast<double>(0.00827873981303895),
    static_cast<double>(0.9787742027878763),
    static_cast<double>(0.002865103798187358),
    static_cast<double>(0.008278739813038918),
    static_cast<double>(8.588725388823207),
    static_cast<double>(0.16557003523380628),
    static_cast<double>(0.0011156171596154317),
    static_cast<double>(0.9787742027878762),
    static_cast<double>(0.16557003523380787),
    static_cast<double>(19.575496476307574),
    static_cast<double>(0.05730212969417545),
    static_cast<double>(0.0028651037981874054),
    static_cast<double>(0.0011156171596155022),
    static_cast<double>(0.057302129694176404),
    static_cast<double>(1.3159809338068882)
  );

  lkf.G = make_DenseMatrix<STATE_SIZE, OUTPUT_SIZE>(
    static_cast<double>(0.04893928924912182),
    static_cast<double>(0.0007413756985857115),
    static_cast<double>(0.008278739813038775),
    static_cast<double>(0.0003047530998279953),
    static_cast<double>(0.978774202787876),
    static_cast<double>(-0.0007950387916633953),
    static_cast<double>(0.0028651037981874054),
    static_cast<double>(-3.439282045136617e-06)
  );

  return lkf;

}

} // namespace servo_motor_constraints_lti_mpc_lkf

#endif // __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_LKF_HPP__
