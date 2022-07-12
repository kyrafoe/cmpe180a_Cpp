#ifndef _TREES_H_
#define _TREES_H_

struct Node{
    Node(int val){data = val;};
    int data;
    Node * left = nullptr;
    Node * right = nullptr;
};


uint countNodes(const Node * MyNode);

void printInOrderLeft(const Node * MyNode);

void printInOrderRight(const Node * MyNode);

int getHeight(const Node * r);

bool isComplete(Node * MyNode);

#endif
