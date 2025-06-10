#ifndef __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_PHI_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_PHI_HPP__

#include "python_numpy.hpp"

namespace servo_motor_constraints_lti_mpc_Phi {

using namespace PythonNumpy;

using SparseAvailable_lti_mpc_Phi =
    SparseAvailable<ColumnAvailable<false, false>,
                    ColumnAvailable<false, false>,
                    ColumnAvailable<false, false>, ColumnAvailable<true, false>,
                    ColumnAvailable<false, false>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, false>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>,
                    ColumnAvailable<true, true>, ColumnAvailable<true, true>>;

using type = SparseMatrix_Type<float, SparseAvailable_lti_mpc_Phi>;

inline auto make(void) -> type {

  return make_SparseMatrix<SparseAvailable_lti_mpc_Phi>(
      static_cast<float>(-0.0008001243789611503),
      static_cast<float>(-0.0019923097036132643),
      static_cast<float>(-0.0008001243789611503),
      static_cast<float>(1.6002408650535357e-05),
      static_cast<float>(-0.0032613695729506544),
      static_cast<float>(-0.0019923097036132643),
      static_cast<float>(7.10506983547919e-05),
      static_cast<float>(1.6002408650535357e-05),
      static_cast<float>(-0.004349278903452052),
      static_cast<float>(-0.0032613695729506544),
      static_cast<float>(0.00018857365688901048),
      static_cast<float>(7.10506983547919e-05),
      static_cast<float>(-0.005050683230750507),
      static_cast<float>(-0.004349278903452052),
      static_cast<float>(0.0003872056455114522),
      static_cast<float>(0.00018857365688901048),
      static_cast<float>(-0.005222063374256641),
      static_cast<float>(-0.005050683230750507),
      static_cast<float>(0.0006769192500758851),
      static_cast<float>(0.0003872056455114522),
      static_cast<float>(-0.004793891946869746),
      static_cast<float>(-0.005222063374256641),
      static_cast<float>(0.0010565879982114327),
      static_cast<float>(0.0006769192500758851),
      static_cast<float>(-0.003779071669904116),
      static_cast<float>(-0.004793891946869746),
      static_cast<float>(0.001513150768613176),
      static_cast<float>(0.0010565879982114327),
      static_cast<float>(-0.002273590199366987),
      static_cast<float>(-0.003779071669904116),
      static_cast<float>(0.0020224665736990966),
      static_cast<float>(0.001513150768613176),
      static_cast<float>(-0.0004474296246384952),
      static_cast<float>(-0.002273590199366987),
      static_cast<float>(0.002551788293842877),
      static_cast<float>(0.0020224665736990966),
      static_cast<float>(0.0014743707881697246),
      static_cast<float>(-0.0004474296246384952),
      static_cast<float>(0.003063592606873353),
      static_cast<float>(0.002551788293842877),
      static_cast<float>(0.0032389344700059367),
      static_cast<float>(0.0014743707881697246),
      static_cast<float>(0.0035203195601469983),
      static_cast<float>(0.003063592606873353),
      static_cast<float>(0.004598091789859283),
      static_cast<float>(0.0032389344700059367),
      static_cast<float>(0.0038894319084983994),
      static_cast<float>(0.0035203195601469983),
      static_cast<float>(0.005342291387148394),
      static_cast<float>(0.004598091789859283),
      static_cast<float>(0.004148127348244415),
      static_cast<float>(0.0038894319084983994),
      static_cast<float>(0.005331435837751551),
      static_cast<float>(0.005342291387148394),
      static_cast<float>(0.004287042779051156),
      static_cast<float>(0.004148127348244415),
      static_cast<float>(0.004518304240415328),
      static_cast<float>(0.005331435837751551),
      static_cast<float>(0.004312384281743267),
      static_cast<float>(0.004287042779051156),
      static_cast<float>(0.0029609334544288594),
      static_cast<float>(0.004518304240415328),
      static_cast<float>(0.004246093076452514),
      static_cast<float>(0.004312384281743267),
      static_cast<float>(0.0008215802990515512),
      static_cast<float>(0.0029609334544288594),
      static_cast<float>(0.004123898038072223),
      static_cast<float>(0.004246093076452514),
      static_cast<float>(-0.0016484577193429037),
      static_cast<float>(0.0008215802990515512));
}

} // namespace servo_motor_constraints_lti_mpc_Phi

#endif // __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_PHI_HPP__
