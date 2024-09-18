#ifndef MY_LINKED_LIST_PROJECT
#define MY_LINKED_LIST_PROJECT

#include <iostream>
#include <memory>

namespace mystd {

  class Node {
  public:
    Node(int value) : data_{ value }, next_{ nullptr } {};
    ~Node() {};
    // Disallow copy constructor aka
    // Node elem1;
    // Node elem2 = elem1;
    Node(const Node&) = delete;
    // Allows copy assignment
    // Node elem1;
    // Node elem2;
    // elem2 = elem1;
    Node& operator=(const Node&) = default;

    int GetData() const { return data_; }
    void SetData(int value) { data_ = value; }
    Node* GetNext() const { return next_; }
    void SetNext(Node* node) { next_ = node; }

  private:
    int data_;
    Node* next_;
  };

  class myLinkedList {
  public:
    explicit myLinkedList();
    ~myLinkedList();
    myLinkedList(const myLinkedList&) = delete;
    myLinkedList& operator=(const myLinkedList&) = default;

    int GetSize() const;
    void PushFront(int value);
    bool IsEmpty() const;
    int GetValueAt(int index) const;
    void PushBack(int value);
    void PrintList() const;
    int PopFront();
    int PopBack();
    void insert(int index, int value);
    void DeleteNode(int index);
    void RemoveValue(int value);

  private:
    Node* Head_;
    int size_{ 0 };
  };
}  // namespace mystd

#endif  // !MY_LINKED_LIST_PROJECT
