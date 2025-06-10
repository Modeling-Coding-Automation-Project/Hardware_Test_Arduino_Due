#include "PythonMPC_Tester.hpp"

PythonMPC_Tester::PythonMPC_Tester() {

  this->_mpc = servo_motor_constraints_lti_mpc::make();
}

PythonMPC_Tester::~PythonMPC_Tester() {}

void PythonMPC_Tester::test_mpc(void) {

  unsigned long time_start = 0;
  unsigned long time_end = 0;

  time_start = micros(); // start measuring.

  time_end = micros(); // end measuring.

  /* send result */
  Serial.begin(9600);

  Serial.println("Result: \n");
  std::stringstream result_stream;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());
}
