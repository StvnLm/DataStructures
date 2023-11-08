/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
typedef struct Node {
    int data;
    Node* next;
    Node* prev;
}* nodePtr;

int main()
{
    
    nodePtr head;
    nodePtr tail;
    nodePtr curr;
    nodePtr tmp;
    
    Node* node = new Node;
    
    node->data = 1;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;
    
    Node* node2 = new Node;
    node->data = 2;
    node->next = nullptr;
    node->prev = tail; 
    tail->next = node2;
    head = node2;
    
    tmp = tail;
    
    while (tmp != nullptr) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
    
    
    return 0;
}
