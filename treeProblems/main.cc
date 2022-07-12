#include"trees.h"

int main()
{
    
    int val = 1;

    Node * MyNode;
    MyNode = new Node(val);
    MyNode->left = new Node(2);
    MyNode->right = new Node(3);
    MyNode->left->left = new Node(4);
    MyNode->left->right = new Node(6); 

    // Check for complete tree
    try{
    if(isComplete(MyNode))
        std::cout << "Complete tree \n";
    else
    {
        throw badTree();
    }
    }
    catch (std::exception& e)
    {
        std::cout << e.what()<<"\n";
    }  
 
    return 0;
}
