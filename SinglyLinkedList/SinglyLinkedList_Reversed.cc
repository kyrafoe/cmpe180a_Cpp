#include"SinglyLinkedList_Reversed.h"
#include<iostream>

void print(Node * current) 
{

    while(current != nullptr) // iterative print
    {
        std::cout << current->data << "\n";
        current = current->next;
    } 
}

void reversePrint(Node * current) 
{
    
    if(current == nullptr) return; // reversePrint recursion

    reversePrint(current->next);
    std::cout << current->data << "\n"; // if the last one is a nullptr start printing
}




void Reverse_Recursive(Node* MyNode, Node * head)
{
    
    if(MyNode->next == nullptr) // traverse complete list and if head = nullptr, then chnage head pointer to last element
    {
        head = MyNode;
        return;
    } 

    Reverse_Recursive(MyNode->next, head); 
    // then going back

    Node * rev = MyNode->next;
    rev->next = MyNode;
    MyNode->next = nullptr; // first Node will point to nullptr
} 

