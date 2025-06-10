#ifndef __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_SOLVER_FACTOR_HPP__
#define __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_SOLVER_FACTOR_HPP__

#include "python_numpy.hpp"

namespace servo_motor_constraints_lti_mpc_solver_factor {

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

  return make_SparseMatrix<SparseAvailable_lti_mpc_solver_factor>(
      static_cast<float>(-0.6171258210073834),
      static_cast<float>(-1.3725300408027499),
      static_cast<float>(0.012342455543448436),
      static_cast<float>(-2.1068111311062814),
      static_cast<float>(0.051518256775655996),
      static_cast<float>(-2.685605387217003),
      static_cast<float>(0.13087129240218684),
      static_cast<float>(-3.003448947895233),
      static_cast<float>(0.259968538638338),
      static_cast<float>(-2.9917674710448092),
      static_cast<float>(0.44267963708095803),
      static_cast<float>(-2.626372534604195),
      static_cast<float>(0.6760902799569566),
      static_cast<float>(-1.9314765844112614),
      static_cast<float>(0.9503576398636346),
      static_cast<float>(-0.978467213380294),
      static_cast<float>(1.2495410405698044),
      static_cast<float>(0.12123853848139629),
      static_cast<float>(1.5533345927696192),
      static_cast<float>(1.228935700983705),
      static_cast<float>(1.8395137834691386),
      static_cast<float>(2.1957415037801655),
      static_cast<float>(2.086805492418752),
      static_cast<float>(2.8821132785806105),
      static_cast<float>(2.2778180634309004),
      static_cast<float>(3.177328702450033),
      static_cast<float>(2.4016380717347374),
      static_cast<float>(3.016313414839396),
      static_cast<float>(2.4557208495393565),
      static_cast<float>(2.3913818689311657),
      static_cast<float>(2.44677353104033),
      static_cast<float>(1.356982624625777),
      static_cast<float>(2.3904461747802137),
      static_cast<float>(0.026358394407459042),
      static_cast<float>(2.3097956538097444),
      static_cast<float>(-1.439948675023277),
      static_cast<float>(0.16411325350563497),
      static_cast<float>(-0.2173428905129947),
      static_cast<float>(-0.003282248881075013),
      static_cast<float>(-0.8897639183998524),
      static_cast<float>(-0.0020535497571873276),
      static_cast<float>(-1.6594842036050326),
      static_cast<float>(0.016908905310290313),
      static_cast<float>(-2.366755564387621),
      static_cast<float>(0.06811276267221114),
      static_cast<float>(-2.8803541620054176),
      static_cast<float>(0.16409131761152657),
      static_cast<float>(-3.1022571451598107),
      static_cast<float>(0.3128777675795793),
      static_cast<float>(-2.9754226305369005),
      static_cast<float>(0.5162697686214405),
      static_cast<float>(-2.4902571872646178),
      static_cast<float>(0.7690003788691017),
      static_cast<float>(-1.686992696254022),
      static_cast<float>(1.058899419023808),
      static_cast<float>(-0.6524585249352243),
      static_cast<float>(1.3680432661746884),
      static_cast<float>(0.489151155429061),
      static_cast<float>(1.6747791033437585),
      static_cast<float>(1.5908979572245134),
      static_cast<float>(1.9563952494436574),
      static_cast<float>(2.5016050294251726),
      static_cast<float>(2.192112855479462),
      static_cast<float>(3.0860632163894977),
      static_cast<float>(2.366012785528325),
      static_cast<float>(3.2443514343007376),
      static_cast<float>(2.4694968020593984),
      static_cast<float>(2.92762204198213),
      static_cast<float>(2.5029199346392335),
      static_cast<float>(2.1480002824860294),
      static_cast<float>(2.4761197667898474),
      static_cast<float>(0.980885765743074));
}

} // namespace servo_motor_constraints_lti_mpc_solver_factor

#endif // __SERVO_MOTOR_CONSTRAINTS_LTI_MPC_SOLVER_FACTOR_HPP__
