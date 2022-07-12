#include "trees.h"
#include <iostream>
#include <bits/stdc++.h> // needed for min, max


struct BadBST : public std::exception
{
	const char *what() const throw()
	{
		return "Tree is no binary search tree";
	}

};

struct badTree: public std::exception
{
  const char* what() const throw()
  {
    return "Tree is not a complete tree";
  }
};


uint countNodes(const Node * MyNode)
{
    if(MyNode == nullptr) return 0;

    uint left = countNodes(MyNode->left);
    
    uint right = countNodes(MyNode->right);
   
    return left + right + 1;
}

void printInOrderLeft(const Node * MyNode)
{
    if(MyNode == nullptr) return;

    
    printInOrderLeft(MyNode->left);
    std::cout<< "MyNode: " << MyNode->data<<"\n";
    printInOrderLeft(MyNode->right);
}

void printInOrderRight(const Node * MyNode)
{
    if(MyNode == nullptr) return;

    
    printInOrderRight(MyNode->right);
    std::cout<< "MyNode: " << MyNode->data<<"\n";
    printInOrderRight(MyNode->left);
}


int getHeight(const Node * r)
{
	int lhs_h = 0, rhs_h = 0;
	if(r->left != nullptr)
		lhs_h = getHeight(r->left);
	if(r->right != nullptr)
		rhs_h = getHeight(r->right);
	
	return std::max(lhs_h, rhs_h) +1; // +1 to get head node
}


// test for complete tree
// level order traversal is done with a queue
// first null node we run into should not be followed by another node
bool isComplete(Node * MyNode)
{

    if(MyNode == nullptr) return true;

    // Save nodes in queue
    std::queue<Node *> tree;
    tree.push(MyNode); // get root node

    // if a nullptr is seen, end = true
    bool end = false;

    while(!tree.empty())
    {
        Node * current = tree.front();
        tree.pop();

        // check for left
        if(current->left)
        {
            if(end == true) return false;
            tree.push(current->left); // add left child to queu
        }
        else
            end = true;
        

        if(current->right)
        {
            if(end == true) return false;
            tree.push(current->right);
        }
        else
            end = true;
    }

    return true;

    throw badTree(); // check this exeption
}




