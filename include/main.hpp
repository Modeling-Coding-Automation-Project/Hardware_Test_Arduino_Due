#ifndef _MAIN_HPP_
#define _MAIN_HPP_

// #include "BaseUtilityTester.hpp"
// #include "PythonMathTester.hpp"
#include "PythonNumpyTester.hpp"

#include <sstream>
#include <stdint.h>
#include <string>

#include <Arduino.h>

#include "Timer/time_manager.hpp"

#define SS0PIN (10)

/* Test Objects */
// BaseUtilityTester base_utility_tester;
// PythonMathTester python_math_tester;
PythonNumpyTester python_numpy_tester;

#endif
