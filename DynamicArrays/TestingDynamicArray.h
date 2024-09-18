#ifndef MY_DYNAMIC_ARRAYS_TESTER
#define MY_DYNAMIC_ARRAYS_TESTER

#include <iostream>

#include "myDynamicArray.h"

namespace mystd {
class myDynamicArrayTester {
 public:
  void RunAllTests();
  void TestSize() const;
  // Tests increases and decreases in capacity based on number of items stored.
  void TestCapacity() const;
  void TestIsEmpty() const;
  void TestGetValueAt() const;
  void TestPop() const;
  void TestInsert() const;
  void TestPrepend() const;
  void TestDelete() const;
  void TestRemove() const;
  void TestFind() const;
};

}  // namespace mystd
#endif  // !MY_DYNAMIC_ARRAYS_TESTER
