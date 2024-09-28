#ifndef MYCIRCULARDEQUE_H
#define MYCIRCULARDEQUE_H

#include "Node.h"

class MyCircularDeque {
private:
    Node* Front;
    Node* Rear;
    int maxsize;
    int size;

public:
    MyCircularDeque(int k);

    bool insertFront(int value);
    bool insertLast(int value);
    bool deleteFront();
    bool deleteLast();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
};

#endif // MYCIRCULARDEQUE_H
