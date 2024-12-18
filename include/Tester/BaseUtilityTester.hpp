#ifndef BASE_UTILITY_TESTER_HPP
#define BASE_UTILITY_TESTER_HPP

#include "base_utility.hpp"

#include <cstring>
#include <sstream>
#include <stdint.h>
#include <string>

#include <Arduino.h>

class BaseUtilityTester {
public:
  /* Constructor */
  BaseUtilityTester();

  /* Destructor */
  ~BaseUtilityTester();

public:
  /* Constant */
  static constexpr std::size_t ARRAY_SIZE = 100;

private:
  /* Variables */
  std::array<float, ARRAY_SIZE> array_copy_source;
  std::array<float, ARRAY_SIZE> array_copy_destination;

public:
  /* Functions */
  void test_copy(void);
};

#endif // BASE_UTILITY_TESTER_HPP