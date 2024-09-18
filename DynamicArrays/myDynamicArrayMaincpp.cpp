#include "TestingDynamicArray.h"
#include "myDynamicArray.h"

int main() {
  std::cout << "Starting All Tests" << "\n";

  mystd::myDynamicArrayTester Tester;

  Tester.RunAllTests();

  return 0;
}
