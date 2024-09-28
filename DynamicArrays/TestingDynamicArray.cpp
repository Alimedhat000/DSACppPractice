#include "TestingDynamicArray.h"

#include <cassert>

namespace mystd {
void myDynamicArrayTester::RunAllTests() {
  TestSize();
  TestIsEmpty();
  TestCapacity();
  TestGetValueAt();
  TestPop();
  TestInsert();
  TestDelete();
  TestRemove();
  TestFind();
  std::cout << "Passed All Tests !!\n";
}
void myDynamicArrayTester::TestSize() const {
  mystd::myDynamicArray vector(3);
  assert(vector.GetSize() == 0);
  int items_to_add = 5;
  for (int i = 0; i < items_to_add; ++i) {
    vector.Push(i + 1);
  }
  assert(vector.GetSize() == items_to_add);
  std::cout << "Passed Size Test\n";
}
void myDynamicArrayTester::TestCapacity() const {
  mystd::myDynamicArray tester(4);

  // test increasing size
  assert(tester.GetCapacity() == mystd::KMinCapacity);
  std::cout << "Passed Capacity Test 1\n";
  for (int i = 0; i < 17; ++i) {
    tester.Push(i + 1);
  }
  assert(tester.GetCapacity() == mystd::KMinCapacity * 2);
  std::cout << "Passed Capacity Test 2\n";
  for (int j = 0; j < 20; ++j) {
    tester.Push(j + 1);
  }
  assert(tester.GetCapacity() == mystd::KMinCapacity * 4);
  std::cout << "Passed Capacity Test 3\n";

  // test decreasing size
  for (int k = 0; k < 30; ++k) {
    tester.Pop();
  }
  assert(tester.GetCapacity() == mystd::KMinCapacity * 2);
  std::cout << "Passed Capacity Test 4\n";

  for (int k = 0; k < 7; ++k) {
    tester.Pop();
  }
  assert(tester.GetCapacity() == mystd::KMinCapacity / 4);
  std::cout << "Passed Capacity Test 5\n";
}
void myDynamicArrayTester::TestIsEmpty() const {
  mystd::myDynamicArray tester(3);
  assert(tester.IsEmpty());
  std::cout << "Passed IsEmpty Test\n";
}
void myDynamicArrayTester::TestGetValueAt() const {
  mystd::myDynamicArray tester(3);
  tester.Push(4);
  tester.Push(9);
  tester.Push(12);
  assert(tester.GetValueAt(0) == 4);
  assert(tester.GetValueAt(1) == 9);
  assert(tester.GetValueAt(2) == 12);
  std::cout << "Passed GetValAt Test\n";
}
void myDynamicArrayTester::TestPop() const {
  mystd::myDynamicArray tester(1);
  tester.Push(3);

  int popped = tester.Pop();
  assert(popped == 3);
  tester.Push(9);
  tester.Push(8);

  assert(tester.GetSize() == 2);
  int popped2 = tester.Pop();
  assert(popped2 == 8);
  assert(tester.GetSize() == 1);
  std::cout << "Passed Pop Test\n";
}
void myDynamicArrayTester::TestInsert() const {
  mystd::myDynamicArray tester(3);
  tester.Push(5);
  tester.Push(7);
  tester.Push(9);
  tester.Insert(0, 4);
  assert(tester.GetValueAt(0) == 4);
  assert(tester.GetValueAt(1) == 5);
  assert(tester.GetValueAt(2) == 7);
  assert(tester.GetValueAt(3) == 9);
  tester.Insert(3, 8);
  assert(tester.GetValueAt(3) == 8);
  assert(tester.GetValueAt(4) == 9);
  std::cout << "Passed Insert Test\n";
}
void myDynamicArrayTester::TestPrepend() const {
  mystd::myDynamicArray tester(3);
  tester.Push(9);
  tester.Push(8);
  tester.Push(7);
  tester.Prepend(6);
  assert(tester.GetSize() == 4);
  assert(tester.GetValueAt(0) == 6);
  assert(tester.GetValueAt(1) == 9);
  assert(tester.GetValueAt(3) == 7);
  std::cout << "Passed Prepend Test\n";
}
void myDynamicArrayTester::TestDelete() const {
  mystd::myDynamicArray tester(1);
  tester.Push(5);
  tester.Delete(0);
  assert(tester.GetSize() == 0);

  tester.Push(9);
  tester.Push(10);
  tester.Push(11);
  tester.Delete(1);
  assert(tester.GetSize() == 2);
  assert(tester.GetValueAt(0) == 9);
  assert(tester.GetValueAt(1) == 11);
  std::cout << "Passed Delete Test\n";
}
void myDynamicArrayTester::TestRemove() const {
  mystd::myDynamicArray tester(5);
  tester.Push(50);
  tester.Push(2);
  tester.Push(50);
  tester.Push(4);
  tester.Push(50);
  tester.Remove(50);
  assert(tester.GetSize() == 2);
  assert(tester.GetValueAt(0) == 2);
  assert(tester.GetValueAt(1) == 4);
  std::cout << "Passed Remove Test\n";
}
void myDynamicArrayTester::TestFind() const {
  mystd::myDynamicArray tester(3);
  tester.Push(4);
  tester.Push(7);
  tester.Push(11);
  assert(tester.Find(5) == -1);
  assert(tester.Find(4) == 0);
  assert(tester.Find(7) == 1);
  assert(tester.Find(11) == 2);
  std::cout << "Passed Find Test\n";
}
}  // namespace mystd
