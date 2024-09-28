#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node* next;
    Node* prev;
    int data;

    Node(int value);
};

#endif // NODE_H
