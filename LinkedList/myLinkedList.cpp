#include "myLinkedList.h"

namespace mystd {
myLinkedList::~myLinkedList() {
  Node* Current = Head_;
  Node* Next = nullptr;

  while (Current) {
    Next = Current->GetNext();
    delete Current;
    Current = Next;
  }
}

int myLinkedList::GetSize() const { return size_; }

void myLinkedList::PushFront(int value) {
  Node* NewNode = new Node(value);

  NewNode->SetNext(Head_);
  Head_ = NewNode;
  size_++;
}

bool myLinkedList::IsEmpty() const { return Head_ == nullptr; }

int myLinkedList::GetValueAt(int index) const {
  Node* TempNode = Head_;
  for (int i = 0; i < index && TempNode != nullptr; i++) {
    TempNode = TempNode->GetNext();
  }

  if (!TempNode) {
    std::cout << "Index Out Of Bounds \n";
    exit(EXIT_FAILURE);
  }
  return TempNode->GetData();
}

void myLinkedList::PushBack(int value) {
  Node* NewNode = new Node(value);
  if (Head_ == nullptr) {
    Head_ = NewNode;

  } else {
    Node* TempNode = Head_;
    while (TempNode->GetNext()) {
      TempNode = TempNode->GetNext();
    }
    TempNode->SetNext(NewNode);
    size_++;
  }
}

void myLinkedList::PrintList() const {
  Node* TempNode = Head_;
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

int myLinkedList::PopFront() {
  if (!Head_) {
    std::cout << "List is Empty \n";
    return -1;
  }
  Node* TempNode = Head_;
  int value = TempNode->GetData();
  Head_ = Head_->GetNext();
  delete TempNode;
  size_--;
  return value;
}

int myLinkedList::PopBack() {
  if (!Head_) {
    std::cout << "List is Empty \n";
    return -1;
  }
  Node* CurNode = Head_;
  Node* PrevNode = nullptr;
  while (CurNode->GetNext()) {
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }

  int value = CurNode->GetData();

  if (PrevNode) {
    PrevNode->SetNext(
        nullptr);  // Ensure that the lists ends here with no dangling pointers
  } else {
    Head_ = nullptr;  // if only one element is in the List
  }

  delete CurNode;
  size_--;
  return value;
}

void myLinkedList::insert(int index, int value) {
  if (index >= size_) {
    PushBack(value);
    return;
  }
  if (index <= 0) {
    PushFront(value);
    return;
  }

  Node* CurNode = Head_;
  Node* PrevNode = nullptr;
  int i{0};
  for (i; i < index && CurNode; i++) {
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }

  Node* NewNode = new Node(value);

  if (PrevNode) {
    NewNode->SetNext(CurNode);
    PrevNode->SetNext(NewNode);
  }
  size_++;
}

void myLinkedList::DeleteNode(int index) {
  if (IsEmpty()) {
    std::cout << "The List is Empty, Can't Delete\n";
    return;
  }

  if (index > size_) {
    std::cout << "Index out of bounds\n";
    return;
  }

  Node* CurNode = Head_;
  Node* PrevNode = nullptr;

  // If deleting the first node (index = 0)
  if (index == 0) {
    Head_ = Head_->GetNext();
    delete CurNode;
    size_--;
    return;
  }

  // Traverse to the node at position 'index'
  for (int i = 0; i < index && CurNode; i++) {
    PrevNode = CurNode;
    CurNode = CurNode->GetNext();
  }

  if (!CurNode) {
    std::cout << "Node doesn't exist at this index\n";
    return;
  }

  PrevNode->SetNext(CurNode->GetNext());  // Disconnect the node
  delete CurNode;                         // Free the memory
  size_--;
}

void myLinkedList::RemoveValue(int value) {
  Node* CurNode = Head_;
  Node* PrevNode = nullptr;

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
