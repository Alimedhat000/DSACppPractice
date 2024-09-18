#if !defined(MY_DYNAMIC_ARRAYS_PROJECT)
#define MY_DYNAMIC_ARRAYS_PROJECT

#include <iostream>
#include <memory>

namespace Ali {
static const int KMinCapacity = 8;
static const int KGrowthFactor = 2;
static const int KShrinkFactor = 4;

class myDynamicArray {
 private:
  // current capacity of the array
  int capacity_{MinCapacity};
  // current number of items in the array
  int size_{0};
  // pointer to the array items
  std::unique_ptr<int[]> data_;

  int DetermineCapacity(int capacity) const;
  void ResizeArray(int New_Size);
  void IncreaseSize();
  void DecreaseSize();

 public:
  myDynamicArray(int capacity);                           // Constructor
  ~myDynamicArray();                                      // Destructor
  myDynamicArray(const myDynamicArray &other) = default;  // Copy Constructor

  int GetSize() const;
  int GetCapacity() const;
  bool IsEmpty() const;
  void PrintArray() const;
  void Push(int value);
  int GetValueAt(int index) const;
  int pop();
  void Insert(int index, int value);
  void Prepend(int value);
  void Delete(int index);
  void Remove(int value);
  int find(int value);
};

}  // namespace Ali
#endif  // MY_DYNAMIC_ARRAYS_PROJECT
