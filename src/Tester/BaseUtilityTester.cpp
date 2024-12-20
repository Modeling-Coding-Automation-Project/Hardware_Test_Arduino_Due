#include "BaseUtilityTester.hpp"

BaseUtilityTester::BaseUtilityTester() : array_copy_destination({}) {

  for (std::size_t i = 0; i < BaseUtilityTester::ARRAY_SIZE; i++) {
    this->array_copy_source[i] = static_cast<float>(i);
  }
}

void BaseUtilityTester::test_copy(void) {
  unsigned long time_start = 0;
  unsigned long time_end = 0;

  time_start = micros(); // start measuring.

  //   for (std::size_t i = 0; i < BaseUtilityTester::ARRAY_SIZE; i++) {
  //     this->array_copy_destination[i] = this->array_copy_source[i];
  //   }

  //   std::memcpy(this->array_copy_destination.data(),
  //               this->array_copy_source.data(),
  //               sizeof(float) * BaseUtilityTester::ARRAY_SIZE);

  //   std::copy(this->array_copy_source.begin(), this->array_copy_source.end(),
  //             this->array_copy_destination.begin());

  Base::Utility::copy<float, BaseUtilityTester::ARRAY_SIZE>(
      this->array_copy_source, this->array_copy_destination);

  time_end = micros(); // end measuring.

  /* send result */
  Serial.begin(9600);

  Serial.println("Result = ");
  std::stringstream result_stream;
  for (std::size_t i = 0; i < BaseUtilityTester::ARRAY_SIZE; i++) {
    result_stream << array_copy_destination[i] << " ";
  }
  result_stream << std::endl;

  std::string result_text = result_stream.str();
  Serial.println(result_text.c_str());

  Serial.print("Calculation time[us]: ");
  Serial.println(time_end - time_start);
}

BaseUtilityTester::~BaseUtilityTester() {}
