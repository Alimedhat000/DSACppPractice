#include "myDynamicArray.h"

namespace Ali {

myDynamicArray::myDynamicArray(int capacity_) {
  if (capacity_ < 1) {
    std::cout << "Invalid Size!!" << "\n";
    exit(EXIT_FAILURE);
  } else {
    int TrueCapacity = DetermineCapacity(capacity_);
    capacity_ = TrueCapacity;
    data_ = std::unique_ptr<int[]>(
        new int[TrueCapacity]);  // Dynamically Construct an array with Size
    // true_capacity
  }
}
myDynamicArray::~myDynamicArray() {}

int myDynamicArray::DetermineCapacity(int capacity_) const {
  int TrueCapacity = KMinCapacity;
  while (capacity_ > TrueCapacity) {
    TrueCapacity *= KGrowthFactor;
  }
  return TrueCapacity;
}

int myDynamicArray::GetSize() const { return size_; }

int myDynamicArray::GetCapacity() const { return capacity_; }

bool myDynamicArray::IsEmpty() const { return size_ == 0; }

void myDynamicArray::PrintArray() const {
  std::cout << "Size: " << size_ << "\n"
            << "Capacity: " << capacity_ << "\n"
            << "items: ";
  for (int i = 0; i < size_; i++) {
    std::cout << i << ": " << data_[i];
  }
  std::cout << "\n";
}

void myDynamicArray::Push(int value) {
  ResizeArray(size_ + 1);
  data_[size_] = value;
  size_++;
}

void myDynamicArray::ResizeArray(int new_size) {
  if (new_size == capacity_) {
    IncreaseSize();
  } else if (new_size < capacity_) {
    DecreaseSize();
  }
}

void myDynamicArray::IncreaseSize() {
  int old_capacity = capacity_;
  int new_capacity = old_capacity * 2;

  std::unique_ptr<int[]> new_data_(new int[new_capacity]);

  for (int i = 0; i < size_; i++) {
    new_data_[i] = data_[i];
  }

  data_ = std::move(new_data_);
  capacity_ = new_capacity;
}

void myDynamicArray::DecreaseSize() {
  int old_capacity = capacity_;
  int new_capacity = old_capacity / 2;

  std::unique_ptr<int[]> new_data(new int[new_capacity]);

  for (int i = 0; i < size_; i++) {
    new_data[i] = data_[i];
  }

  data_ = std::move(new_data);
  capacity_ = new_capacity;
}

int myDynamicArray::GetValueAt(int index) const {
  if (index < 0 or index >= size_) {
    std::cout << "Invalid Index" << "\n";
    exit(EXIT_FAILURE);
  }
  return data_[index];
}

int myDynamicArray::pop() {
  if (size_ == 0) {
    std::cout << "No Values to be Poped" << "\n";
    exit(EXIT_FAILURE);
  }
  int value = data_[size_ - 1];
  ResizeArray(size_ - 1);
  size_--;
  return value;
}

void myDynamicArray::Insert(int index, int value) {
  if (index < 0 or index >= size_) {
    std::cout << "Invalid Index" << "\n";
    exit(EXIT_FAILURE);
  }
  ResizeArray(size_ + 1);

  for (int i = size_; i > index; i--) {
    data_[i] = data_[i - 1];
  }
  data_[index] = value;

  size_++;
}
void myDynamicArray::Prepend(int value) { Insert(0, value); }
void myDynamicArray::Delete(int index) {
  if (index < 0 or index >= size_) {
    std::cout << "Invalid Index" << "\n";
    exit(EXIT_FAILURE);
  }
  ResizeArray(size_ - 1);

  for (int i = index; i < size_ - 1; i++) {
    data_[i] = data_[i + 1];
  }

  size_--;
}
void myDynamicArray::Remove(int value) {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == value) {
      Delete(i);
      i--;  // As all the items will shift to the left the next item  have the
      // current index so we have to decerement
    }
  }
}
int myDynamicArray::find(int value) {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == value) {
      return i;
    }
  }
  return -1;
}
}  // namespace Ali
