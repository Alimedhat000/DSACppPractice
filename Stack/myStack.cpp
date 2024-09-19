#include "myStack.h"

namespace mystd {
template <typename T>
myStack<T>::~myStack() {
  Node<T>* CurNode = Top_;
  Node<T>* NextNode = nullptr;

  while (CurNode) {
    NextNode = CurNode->GetNext();
    delete CurNode;
    CurNode = NextNode;
  }
}

template <typename T>
void myStack<T>::Push(T value) {
  Node<T>* New_Node = new Node<T>(value);
  New_Node->SetNext(Top_);
  Top_ = New_Node;
}

template <typename T>
T myStack<T>::Pop() {
  if (!Top_) {
    std::cout << "The Stack is Empty \n";
    exit(EXIT_FAILURE);
  }
  T data = Top_->GetData();
  Node<T>* TempNode = Top_;
  Top_ = Top_->GetNext();
  delete TempNode;
  return data;
}

template <typename T>
void myStack<T>::PrintStack() const {
  Node<T>* CurNode = Top_;
  while (CurNode) {
    std::cout << "| " << CurNode->GetData() << " |\n";
    CurNode = CurNode->GetNext();
  }
  std::cout << "| __ |\n";
}

template <typename T>
T myStack<T>::Peek() const {
  if (IsEmpty()) {
    std::cout << "The Stack is Empty \n";
    exit(EXIT_FAILURE);
  }
  return Top_->GetData();
}

template <typename T>
bool myStack<T>::IsEmpty() const {
  return Top_ == nullptr;
}

template <typename T>
void myStack<T>::SortStack() {
  myStack<T> TempStack;
  while (!IsEmpty()) {
    T value = Pop();

    while (value < TempStack.Peek() && !TempStack.IsEmpty()) {
      Push(TempStack.Pop());
    }
    TempStack.Push(value);
  }
  while (!TempStack.IsEmpty()) {
    Push(TempStack.Pop());
  }
}

}  // namespace mystd
