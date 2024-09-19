#include "myLinkedList.h"

namespace mystd {

template <typename T>
myLinkedList<T>::~myLinkedList() {
  Node<T>* Current = Head_;
  Node<T>* Next = nullptr;

  while (Current) {
    Next = Current->GetNext();
    delete Current;
    Current = Next;
  }
}

template <typename T>
int myLinkedList<T>::GetSize() const {
  return size_;
}

template <typename T>
void myLinkedList<T>::PushFront(T value) {
  Node<T>* NewNode = new Node<T>(value);

  NewNode->SetNext(Head_);
  Head_ = NewNode;
  size_++;
}

template <typename T>
bool myLinkedList<T>::IsEmpty() const {
  return Head_ == nullptr;
}

template <typename T>
T myLinkedList<T>::GetValueAt(int index) const {
  Node<T>* TempNode = Head_;
  for (int i = 0; i < index && TempNode != nullptr; i++) {
    TempNode = TempNode->GetNext();
  }

  if (!TempNode) {
    std::cout << "Index Out Of Bounds \n";
    exit(EXIT_FAILURE);
  }
  return TempNode->GetData();
}

template <typename T>
void myLinkedList<T>::PushBack(T value) {
  Node<T>* NewNode = new Node<T>(value);
  if (Head_ == nullptr) {
    Head_ = NewNode;

  } else {
    Node<T>* TempNode = Head_;
    while (TempNode->GetNext()) {
      TempNode = TempNode->GetNext();
    }
    TempNode->SetNext(NewNode);
    size_++;
  }
}

template <typename T>
void myLinkedList<T>::PrintList() const {
  Node<T>* TempNode = Head_;
  if (!TempNode) {
    std::cout << "Empty List \n";
    return;
  }

  while (TempNode) {
    std::cout << TempNode->GetData() << "-> ";
    TempNode = TempNode->GetNext();
  }

  std::cout << "\n";
}

template <typename T>
T myLinkedList<T>::PopFront() {
  if (!Head_) {
    std::cout << "List is Empty \n";
    return T();  // Return default value of T
  }
  Node<T>* TempNode = Head_;
  T value = TempNode->GetData();
  Head_ = Head_->GetNext();
  delete TempNode;
  size_--;
  return value;
}

template <typename T>
T myLinkedList<T>::PopBack() {
  if (!Head_) {
    std::cout << "List is Empty \n";
    return T();  // Return default value of T
  }
  Node<T>* CurNode = Head_;
  Node<T>* PrevNode = nullptr;
  while (CurNode->GetNext()) {
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }

  T value = CurNode->GetData();

  if (PrevNode) {
    PrevNode->SetNext(
        nullptr);  // Ensure that the list ends here with no dangling pointers
  } else {
    Head_ = nullptr;  // if only one element is in the List
  }

  delete CurNode;
  size_--;
  return value;
}

template <typename T>
void myLinkedList<T>::insert(int index, T value) {
  if (index >= size_) {
    PushBack(value);
    return;
  }
  if (index <= 0) {
    PushFront(value);
    return;
  }

  Node<T>* CurNode = Head_;
  Node<T>* PrevNode = nullptr;
  int i{0};
  for (i; i < index && CurNode; i++) {
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }

  Node<T>* NewNode = new Node<T>(value);

  if (PrevNode) {
    NewNode->SetNext(CurNode);
    PrevNode->SetNext(NewNode);
  }
  size_++;
}

template <typename T>
void myLinkedList<T>::DeleteNode(int index) {
  if (IsEmpty()) {
    std::cout << "The List is Empty, Can't Delete\n";
    return;
  }

  if (index > size_) {
    std::cout << "Index out of bounds\n";
    return;
  }

  Node<T>* CurNode = Head_;
  Node<T>* PrevNode = nullptr;

  if (index == 0) {
    Head_ = Head_->GetNext();
    delete CurNode;
    size_--;
    return;
  }

  for (int i = 0; i < index && CurNode; i++) {
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }

  if (!CurNode) {
    std::cout << "Node doesn't exist at this index\n";
    return;
  }

  PrevNode->SetNext(CurNode->GetNext());
  delete CurNode;
  size_--;
}

template <typename T>
void myLinkedList<T>::RemoveValue(T value) {
  Node<T>* CurNode = Head_;
  Node<T>* PrevNode = nullptr;

  while (CurNode) {
    if (CurNode->GetData() == value) {
      if (PrevNode) {
        PrevNode->SetNext(CurNode->GetNext());
      } else {
        Head_ = CurNode->GetNext();
      }
      delete CurNode;
      break;
    }
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }
}

}  // namespace mystd
