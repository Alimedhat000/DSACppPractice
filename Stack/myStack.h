#ifndef MY_STACK_PROJECT
#define MY_STACK_PROJECT

#include <iostream>
#include <memory>

namespace mystd {

template <typename T>
class Node {
 public:
  Node(T value) : data_{value}, next_{nullptr} {};
  ~Node() {};

  Node(const Node&) = delete;
  Node& operator=(const Node&) = default;

  T GetData() const { return data_; }
  void SetData(T value) { data_ = value; }
  Node* GetNext() const { return next_; }
  void SetNext(Node* node) { next_ = node; }

 private:
  T data_;
  Node* next_;
};

template <typename T>
class myStack {
 public:
  explicit myStack() : Top_(nullptr) {};
  ~myStack();
  myStack(const myStack&) = delete;
  myStack& operator=(const myStack&) = default;

  void Push(T value);
  T Pop();
  void PrintStack() const;
  T Peek() const;
  bool IsEmpty() const;
  void SortStack();

 private:
  Node<T>* Top_;
};
}  // namespace mystd

#endif  // !MY_STACK_PROJECT
