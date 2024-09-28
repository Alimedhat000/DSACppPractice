#include "myDeque.h"

MyCircularDeque::MyCircularDeque(int k) {
    maxsize = k;
    Front = nullptr;
    Rear = nullptr;
    size = 0;
}

bool MyCircularDeque::insertFront(int value) {
    if (Front == nullptr) {
        Front = new Node(value);
        Rear = Front;
        size++;
        return true;
    }
    if (size == maxsize) {
        return false;
    }
    Node* newNode = new Node(value);
    Front->prev = newNode;
    newNode->next = Front;
    Front = newNode;
    size++;
    return true;
}

bool MyCircularDeque::insertLast(int value) {
    if (Front == nullptr) {
        Front = new Node(value);
        Rear = Front;
        size++;
        return true;
    }
    if (size == maxsize) {
        return false;
    }
    Node* newNode = new Node(value);
    Rear->next = newNode;
    newNode->prev = Rear;
    Rear = newNode;
    size++;
    return true;
}

bool MyCircularDeque::deleteFront() {
    if (Front == nullptr) {
        return false;
    }
    if (Front == Rear) {
        delete Front;
        Front = Rear = nullptr;
        size--;
        return true;
    }
    Node* tempNode = Front;
    Front = Front->next;
    Front->prev = nullptr;
    delete tempNode;
    size--;
    return true;
}

bool MyCircularDeque::deleteLast() {
    if (Front == nullptr) {
        return false;
    }
    if (Front == Rear) {
        delete Front;
        Front = Rear = nullptr;
        size--;
        return true;
    }
    Node* tempNode = Rear;
    Rear = Rear->prev;
    Rear->next = nullptr;
    delete tempNode;
    size--;
    return true;
}

int MyCircularDeque::getFront() {
    return Front ? Front->data : -1;
}

int MyCircularDeque::getRear() {
    return Front ? Rear->data : -1;
}

bool MyCircularDeque::isEmpty() {
    return Front == nullptr;
}

bool MyCircularDeque::isFull() {
    return size == maxsize;
}
