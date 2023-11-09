#include <iostream>

using namespace std;
typedef struct Node {
    int data;
    Node* next;
    Node* prev;
}* nodePtr;


void printForward(Node*& head) {
    nodePtr current = head;
    std::cout << "nullptr -> ";
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}


void printBackward(Node*& tail) {

}

int main()
{
    
    nodePtr node;
    nodePtr head;
    nodePtr tail;
    node = new Node;
    
    node->data = 4;
    node->next = nullptr;
    node->prev = nullptr;
    
    head = node;
    tail = node;
    
    node = new Node;
    node->data = 5;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    node = new Node;
    node->data = 6;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    node = new Node;
    node->data = 7;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    
    printForward(head);
}
