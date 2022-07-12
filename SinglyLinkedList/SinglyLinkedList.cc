#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList(){}


SinglyLinkedList::~SinglyLinkedList()
{
    std::cout << "Deconstructor is called, when class goes out of scope \n";
    while (!empty())
    {
        (void) pop_front(); // void means return sth but we don't need it
    }
}  

struct IndexOutofBounds : public std::exception
{
	const char *what() const throw()
	{
		return "Index out of bounds, provide bigger index";
	}

};

struct EmptyList : public std::exception
{
	const char *what() const throw()
	{
		return "List is already empty";
	}

};


void SinglyLinkedList::insertAtHead(int input)
{
    head = new Node(input, head); // pass data (input) and next pointer (head)

    if(tail == nullptr) // only insert a tail pointer, if tail is nullptr
    {
        tail = head;
    }   
    sizeLL++;
}


void SinglyLinkedList::print() const
{
    Node * current = head;   

    while(current != nullptr)
    {
        std::cout << current->data << "\n";
        current = current->next;
    }
}




void SinglyLinkedList::insertAtTail(int input)
{
    Node * lastNode = new Node(input, nullptr);
    Node * current = head;

    if(head == nullptr) // in case the head is a nullptr
        head = lastNode;
    else if (current->next == nullptr)
        tail = lastNode;
        
    if(tail!= nullptr)
        tail->next = lastNode;
    
    sizeLL++; 
}


int SinglyLinkedList::size() const
{
    return sizeLL;
}

   
bool SinglyLinkedList::empty() const
{ 
        if (sizeLL == 0)
            return true;

    return false;
}



void SinglyLinkedList::insertAtPosition(int n, int input)
{
    n = n+1;
    Node * insertNode = new Node(input, nullptr);   
    int index = 0;

    if(n == 0)
        throw IndexOutofBounds(); // throw exemption

    if(head == nullptr) // in case the head is a nullptr
        head = insertNode;
    else if (n == 1)
    {
        insertNode->next = head;
        head = insertNode;
    }
    else
    {        
        Node* temp = head;
        for(int i = 1; i < n-1; i++) 
        {
            if(temp != nullptr) 
            {
                temp = temp->next;
            }
        }

        if(temp != nullptr) 
        {
            insertNode->next = temp->next;
            temp->next = insertNode; 
        }         
    }
    sizeLL++; 
} 


int SinglyLinkedList::getPosition(int n) const
{
    int index = 0;
    int value;
    if(head == nullptr) // in case the head is a nullptr
        throw IndexOutofBounds(); // throw exemption
    else
    { 
        Node * temp = head;
        while (temp->next !=nullptr)       
        {          
            if(index == n)
            {
                value = temp->data;
            }
            else if(index+1 == n)
            {
                value = temp->next->data;
            }
            temp = temp->next; // traverse linked list
            index++;
        }  
    } 
    return value;
}


int SinglyLinkedList::pop_front() 
{
    if (head == nullptr)
        throw EmptyList();
    else
    {
        int firstElement = head->data;
        Node * temp = head;
        head = head->next;
        delete temp;

        sizeLL--;
        return firstElement;
    }   
}

 
void SinglyLinkedList::pop_end()
{
    Node *current= head;
    Node *previous;
    
    while(current->next!= nullptr)
    {
      previous=current;
      current=current->next;	
    }
    tail=previous;
    previous->next=nullptr;
    delete current;

    sizeLL--;
}  

