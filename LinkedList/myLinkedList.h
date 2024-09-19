#ifndef MY_LINKED_LIST_PROJECT
#define MY_LINKED_LIST_PROJECT

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
class myLinkedList {
 public:
  explicit myLinkedList() : Head_(nullptr), size_(0) {};
  ~myLinkedList();
  myLinkedList(const myLinkedList&) = delete;
  myLinkedList& operator=(const myLinkedList&) = default;

  int GetSize() const;
  void PushFront(T value);
  bool IsEmpty() const;
  T GetValueAt(int index) const;
  void PushBack(T value);
  void PrintList() const;
  T PopFront();
  T PopBack();
  void insert(int index, T value);
  void DeleteNode(int index);
  void RemoveValue(T value);

 private:
  Node<T>* Head_;
  int size_{0};
};

}  // namespace mystd

#endif  // MY_LINKED_LIST_PROJECT
