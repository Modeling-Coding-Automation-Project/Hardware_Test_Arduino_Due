#ifndef __MAIN_HPP__
#define __MAIN_HPP__

// #include "BaseUtilityTester.hpp"
// #include "PythonMathTester.hpp"
#include "PythonControlTester.hpp"
// #include "PythonNumpyTester.hpp"

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
PythonControlTester python_control_tester;

#endif // __MAIN_HPP__
