#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

struct Node{
    Node(int v, Node * link){data = v; next = link;} // One note consists of data and next pointer
    int data;
    Node * next;
};


class SinglyLinkedList
{
public:
    SinglyLinkedList();
    virtual ~SinglyLinkedList();

    void insertAtHead(int input);
    void print() const;
    void insertAtTail(int input);
    int size() const;
    bool empty() const;
    void insertAtPosition(int n, int input);
    int getPosition(int n) const;
    int pop_front() ;
    void pop_end();

    
private:
    Node * head;
    Node * tail = nullptr;
    int sizeLL = 0;
};

#endif
