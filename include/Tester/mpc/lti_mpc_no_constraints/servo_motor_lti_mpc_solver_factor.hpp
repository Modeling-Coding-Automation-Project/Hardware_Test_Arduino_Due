#ifndef SERVO_MOTOR_LTI_MPC_SOLVER_FACTOR_HPP_
#define SERVO_MOTOR_LTI_MPC_SOLVER_FACTOR_HPP_

#include "python_numpy.hpp"

namespace servo_motor_lti_mpc_solver_factor {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_solver_factor = SparseAvailable<
    ColumnAvailable<false, false, false, true, false, true, true, true, true,
                    true, true, true, true, true, true, true, true, true, true,
                    true, true, true, true, true, true, true, true, true, true,
                    true, true, true, true, true, true, true, true, true, true,
                    true>,
    ColumnAvailable<false, false, false, true, false, true, true, true, true,
                    true, true, true, true, true, true, true, true, true, true,
                    true, true, true, true, true, true, true, true, true, true,
                    true, true, true, true, true, true, true, true, true, true,
                    true>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_solver_factor>;

inline auto make(void) -> type {

  auto result =
      make_SparseMatrixZeros<float, SparseAvailable_lti_mpc_solver_factor>();

  result.unsafe_access(0) = static_cast<float>(-0.6171258210073834);
  result.unsafe_access(1) = static_cast<float>(-1.3725300408027499);
  result.unsafe_access(2) = static_cast<float>(0.012342455543448438);
  result.unsafe_access(3) = static_cast<float>(-2.1068111311062814);
  result.unsafe_access(4) = static_cast<float>(0.051518256775655996);
  result.unsafe_access(5) = static_cast<float>(-2.685605387217003);
  result.unsafe_access(6) = static_cast<float>(0.13087129240218687);
  result.unsafe_access(7) = static_cast<float>(-3.0034489478952326);
  result.unsafe_access(8) = static_cast<float>(0.2599685386383381);
  result.unsafe_access(9) = static_cast<float>(-2.9917674710448092);
  result.unsafe_access(10) = static_cast<float>(0.44267963708095814);
  result.unsafe_access(11) = static_cast<float>(-2.6263725346041955);
  result.unsafe_access(12) = static_cast<float>(0.6760902799569566);
  result.unsafe_access(13) = static_cast<float>(-1.9314765844112614);
  result.unsafe_access(14) = static_cast<float>(0.9503576398636348);
  result.unsafe_access(15) = static_cast<float>(-0.9784672133802944);
  result.unsafe_access(16) = static_cast<float>(1.249541040569804);
  result.unsafe_access(17) = static_cast<float>(0.12123853848139422);
  result.unsafe_access(18) = static_cast<float>(1.5533345927696185);
  result.unsafe_access(19) = static_cast<float>(1.228935700983703);
  result.unsafe_access(20) = static_cast<float>(1.8395137834691395);
  result.unsafe_access(21) = static_cast<float>(2.1957415037801677);
  result.unsafe_access(22) = static_cast<float>(2.0868054924187525);
  result.unsafe_access(23) = static_cast<float>(2.882113278580613);
  result.unsafe_access(24) = static_cast<float>(2.277818063430901);
  result.unsafe_access(25) = static_cast<float>(3.177328702450034);
  result.unsafe_access(26) = static_cast<float>(2.4016380717347374);
  result.unsafe_access(27) = static_cast<float>(3.0163134148393973);
  result.unsafe_access(28) = static_cast<float>(2.4557208495393565);
  result.unsafe_access(29) = static_cast<float>(2.3913818689311666);
  result.unsafe_access(30) = static_cast<float>(2.44677353104033);
  result.unsafe_access(31) = static_cast<float>(1.356982624625777);
  result.unsafe_access(32) = static_cast<float>(2.390446174780213);
  result.unsafe_access(33) = static_cast<float>(0.026358394407457672);
  result.unsafe_access(34) = static_cast<float>(2.3097956538097435);
  result.unsafe_access(35) = static_cast<float>(-1.4399486750232797);
  result.unsafe_access(36) = static_cast<float>(0.1641132535056351);
  result.unsafe_access(37) = static_cast<float>(-0.2173428905129945);
  result.unsafe_access(38) = static_cast<float>(-0.0032822488810750152);
  result.unsafe_access(39) = static_cast<float>(-0.8897639183998521);
  result.unsafe_access(40) = static_cast<float>(-0.0020535497571873363);
  result.unsafe_access(41) = static_cast<float>(-1.659484203605032);
  result.unsafe_access(42) = static_cast<float>(0.016908905310290292);
  result.unsafe_access(43) = static_cast<float>(-2.366755564387621);
  result.unsafe_access(44) = static_cast<float>(0.06811276267221111);
  result.unsafe_access(45) = static_cast<float>(-2.880354162005417);
  result.unsafe_access(46) = static_cast<float>(0.16409131761152657);
  result.unsafe_access(47) = static_cast<float>(-3.1022571451598107);
  result.unsafe_access(48) = static_cast<float>(0.3128777675795793);
  result.unsafe_access(49) = static_cast<float>(-2.9754226305369014);
  result.unsafe_access(50) = static_cast<float>(0.5162697686214406);
  result.unsafe_access(51) = static_cast<float>(-2.490257187264618);
  result.unsafe_access(52) = static_cast<float>(0.7690003788691018);
  result.unsafe_access(53) = static_cast<float>(-1.6869926962540225);
  result.unsafe_access(54) = static_cast<float>(1.0588994190238072);
  result.unsafe_access(55) = static_cast<float>(-0.6524585249352265);
  result.unsafe_access(56) = static_cast<float>(1.3680432661746877);
  result.unsafe_access(57) = static_cast<float>(0.48915115542905757);
  result.unsafe_access(58) = static_cast<float>(1.6747791033437591);
  result.unsafe_access(59) = static_cast<float>(1.5908979572245139);
  result.unsafe_access(60) = static_cast<float>(1.956395249443658);
  result.unsafe_access(61) = static_cast<float>(2.5016050294251753);
  result.unsafe_access(62) = static_cast<float>(2.1921128554794627);
  result.unsafe_access(63) = static_cast<float>(3.086063216389498);
  result.unsafe_access(64) = static_cast<float>(2.366012785528325);
  result.unsafe_access(65) = static_cast<float>(3.2443514343007394);
  result.unsafe_access(66) = static_cast<float>(2.4694968020593984);
  result.unsafe_access(67) = static_cast<float>(2.927622041982132);
  result.unsafe_access(68) = static_cast<float>(2.502919934639234);
  result.unsafe_access(69) = static_cast<float>(2.1480002824860307);
  result.unsafe_access(70) = static_cast<float>(2.476119766789847);
  result.unsafe_access(71) = static_cast<float>(0.9808857657430741);

  return result;
}

} // namespace servo_motor_lti_mpc_solver_factor

#endif // SERVO_MOTOR_LTI_MPC_SOLVER_FACTOR_HPP_
