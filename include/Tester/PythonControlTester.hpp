#ifndef __PYTHON_CONTROL_TESTER_HPP__
#define __PYTHON_CONTROL_TESTER_HPP__

#define USE_EIGEN_LIBRARY (0)

#include "python_control.hpp"

#include <sstream>
#include <stdint.h>
#include <string>

#include <Arduino.h>

class PythonControlTester {
public:
  /* Constructor */
  PythonControlTester();

  /* Destructor */
  ~PythonControlTester();

public:
  /* Functions */
  void test_ls(void);

private:
  /* Variables */
};

#endif // __PYTHON_CONTROL_TESTER_HPP__
