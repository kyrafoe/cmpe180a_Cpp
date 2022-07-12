#ifndef _SINGLY_LINKED_LISTREV_H_
#define _SINGLY_LINKED_LISTREV_H_

struct Node{
    Node(int v, Node * link){data = v; next = link;} // One note consists of data and next pointer
    int data;
    Node * next;
};


struct NodeReverse{
    NodeReverse(int v, Node * right, Node * left){data = v; next = right; prev = left;} // One note consists of data and next pointer
    int data;
    Node * next, * prev;
};


void insertAtHead(Node * head, Node * tail, int input);

void print(Node * current);

void reversePrint(Node * current, Node * head) ;

#endif
