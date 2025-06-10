#ifndef __SERVO_MOTOR_LTI_MPC_HPP__
#define __SERVO_MOTOR_LTI_MPC_HPP__

#include "servo_motor_lti_mpc_F.hpp"
#include "servo_motor_lti_mpc_Phi.hpp"
#include "servo_motor_lti_mpc_lkf.hpp"
#include "servo_motor_lti_mpc_solver_factor.hpp"


#include "python_mpc.hpp"

namespace servo_motor_lti_mpc {

using namespace PythonNumpy;
using namespace PythonControl;
using namespace PythonMPC;

constexpr std::size_t NP = 20;
constexpr std::size_t NC = 2;

constexpr std::size_t INPUT_SIZE = servo_motor_lti_mpc_lkf::INPUT_SIZE;
constexpr std::size_t STATE_SIZE = servo_motor_lti_mpc_lkf::STATE_SIZE;
constexpr std::size_t OUTPUT_SIZE = servo_motor_lti_mpc_lkf::OUTPUT_SIZE;

constexpr std::size_t AUGMENTED_STATE_SIZE = STATE_SIZE + OUTPUT_SIZE;

constexpr std::size_t NUMBER_OF_DELAY =
    servo_motor_lti_mpc_lkf::NUMBER_OF_DELAY;

using LKF_Type = servo_motor_lti_mpc_lkf::type;

using F_Type = servo_motor_lti_mpc_F::type;

using Phi_Type = servo_motor_lti_mpc_Phi::type;

using SolverFactor_Type = servo_motor_lti_mpc_solver_factor::type;

using PredictionMatrices_Type =
    MPC_PredictionMatrices_Type<F_Type, Phi_Type, NP, NC, INPUT_SIZE,
                                AUGMENTED_STATE_SIZE, OUTPUT_SIZE>;

using Ref_Type = DenseMatrix_Type<float, OUTPUT_SIZE, 1>;

using ReferenceTrajectory_Type = MPC_ReferenceTrajectory_Type<Ref_Type, NP>;

using type =
    LTI_MPC_NoConstraints_Type<LKF_Type, PredictionMatrices_Type,
                               ReferenceTrajectory_Type, SolverFactor_Type>;

inline auto make() -> type {

  auto kalman_filter = servo_motor_lti_mpc_lkf::make();

  auto F = servo_motor_lti_mpc_F::make();

  auto Phi = servo_motor_lti_mpc_Phi::make();

  auto solver_factor = servo_motor_lti_mpc_solver_factor::make();

  PredictionMatrices_Type prediction_matrices(F, Phi);

  ReferenceTrajectory_Type reference_trajectory;

  auto lti_mpc_nc = make_LTI_MPC_NoConstraints(
      kalman_filter, prediction_matrices, reference_trajectory, solver_factor);

  return lti_mpc_nc;
}

} // namespace servo_motor_lti_mpc

#endif // __SERVO_MOTOR_LTI_MPC_HPP__
