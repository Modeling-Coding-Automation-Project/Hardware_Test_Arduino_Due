#ifndef MAIN_HPP_
#define MAIN_HPP_

// #include "BaseUtilityTester.hpp"
// #include "PythonMathTester.hpp"
// #include "PythonNumpyTester.hpp"
// #include "PythonControlTester.hpp"
#include "PythonMPC_Tester.hpp"

#include <sstream>
#include <stdint.h>
#include <string>

#include <Arduino.h>

#include "Timer/time_manager.hpp"

#define SS0PIN (10)

/* Test Objects */
// BaseUtilityTester base_utility_tester;
// PythonMathTester python_math_tester;
// PythonNumpyTester python_numpy_tester;
// PythonControlTester python_control_tester;
PythonMPC_Tester python_mpc_tester;

#endif // MAIN_HPP_
