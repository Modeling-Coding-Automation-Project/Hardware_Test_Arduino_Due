#include "BaseUtilityTester.hpp"

BaseUtilityTester::BaseUtilityTester() {

  for (std::size_t i = 0; i < BaseUtilityTester::ARRAY_SIZE; i++) {
    this->array_copy_source[i] = static_cast<float>(i);
  }
}

BaseUtilityTester::~BaseUtilityTester() {}
