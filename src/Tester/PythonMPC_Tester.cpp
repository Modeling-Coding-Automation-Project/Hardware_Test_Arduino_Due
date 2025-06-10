#include "PythonMPC_Tester.hpp"

PythonMPC_Tester::PythonMPC_Tester() {

#if LTI_MPC_USE_CONSTRAINTS == 0
  this->_mpc = servo_motor_lti_mpc::make();
#else
  this->_mpc = servo_motor_constraints_lti_mpc::make();
#endif // LTI_MPC_USE_CONSTRAINTS == 0
}

PythonMPC_Tester::~PythonMPC_Tester() {}

void PythonMPC_Tester::test_mpc(void) {

  /* Define State Space */
  using A_Type = PythonNumpy::SparseAvailable<
      PythonNumpy::ColumnAvailable<true, true, false, false>,
      PythonNumpy::ColumnAvailable<true, true, true, false>,
      PythonNumpy::ColumnAvailable<false, false, true, true>,
      PythonNumpy::ColumnAvailable<true, false, true, true>>;

  auto A = PythonNumpy::make_SparseMatrix<A_Type>(
      static_cast<float>(1.0), static_cast<float>(0.05),
      static_cast<float>(-2.5603853840856576),
      static_cast<float>(0.9500002466138069),
      static_cast<float>(0.12801926920428286), static_cast<float>(1.0),
      static_cast<float>(0.05), static_cast<float>(6.400995031689203),
      static_cast<float>(-0.3200497515844601),
      static_cast<float>(0.4900000000000001));

  using B_Type = PythonNumpy::SparseAvailable<
      PythonNumpy::ColumnAvailable<false>, PythonNumpy::ColumnAvailable<false>,
      PythonNumpy::ColumnAvailable<false>, PythonNumpy::ColumnAvailable<true>>;

  auto B = PythonNumpy::make_SparseMatrix<B_Type>(
      static_cast<float>(0.04999999999999999));

  using C_Type = PythonNumpy::SparseAvailable<
      PythonNumpy::ColumnAvailable<true, false, false, false>,
      PythonNumpy::ColumnAvailable<true, false, true, false>>;

  auto C = PythonNumpy::make_SparseMatrix<C_Type>(
      static_cast<float>(1.0), static_cast<float>(1280.1990063378407),
      static_cast<float>(-64.00995031689203));

  // using D_Type =
  //     PythonNumpy::SparseAvailable<PythonNumpy::ColumnAvailable<false>,
  //                                  PythonNumpy::ColumnAvailable<false>>;

  auto D = PythonNumpy::make_SparseMatrixEmpty<float, 2, 1>();

  float dt = 0.05F;

  auto sys = PythonControl::make_DiscreteStateSpace(A, B, C, D, dt);

  /* Define reference */
  servo_motor_constraints_lti_mpc::Ref_Type ref;

  auto U = PythonControl::make_StateSpaceInput<INPUT_SIZE>(0.0F);

  /* State Space Simulation */
  unsigned long time_start[PythonMPC_Tester::SIM_STEP_MAX] = {0};
  unsigned long time_end[PythonMPC_Tester::SIM_STEP_MAX] = {0};

  std::array<PythonControl::StateSpaceOutput_Type<
                 float, PythonMPC_Tester::OUTPUT_SIZE>,
             PythonMPC_Tester::SIM_STEP_MAX>
      y_array;
  std::array<
      PythonControl::StateSpaceInput_Type<float, PythonMPC_Tester::INPUT_SIZE>,
      PythonMPC_Tester::SIM_STEP_MAX>
      u_array;

  for (std::size_t sim_step = 0; sim_step < PythonMPC_Tester::SIM_STEP_MAX;
       ++sim_step) {
    /* system response */
    sys.update(U);

    /* controller */
    for (std::size_t i = 0; i < ref.rows(); ++i) {
      ref(0, i) = 1.0F;
    }

    time_start[sim_step] = micros(); // start measuring.

    U = this->_mpc.update(ref, sys.get_Y());

    time_end[sim_step] = micros(); // end measuring.

    /* store result */
    y_array[sim_step] = sys.get_Y();
    u_array[sim_step] = U;
  }

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;
  result_stream << std::scientific << std::setprecision(7);

  result_stream << "Y[0], Y[1], U[0], Calculation time[us]" << std::endl;
  for (std::size_t i = 0; i < PythonMPC_Tester::SIM_STEP_MAX; i++) {
    result_stream << y_array[i](0, 0) << ", ";
    result_stream << y_array[i](1, 0) << ", ";
    result_stream << u_array[i](0, 0) << ", ";
    result_stream << time_end[i] - time_start[i];

    result_stream << std::endl;
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}
