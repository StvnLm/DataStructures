#include <iostream>
// TODO : Check index out of bounds, or if initial list is empty.

using namespace std;
typedef struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {};
}* nodePtr;


void insertNodeInFront(Node*& head, int data) {
    nodePtr tempNode = new Node(data);
    tempNode->prev = head;
    head->next = tempNode;
    head = tempNode;
}

void insertNodeAfterIndex(Node*& tail, int data, int index) {
    nodePtr indexNode;
    indexNode = tail;
    for (int i = 0; i < index; i++) {
        indexNode = indexNode->next;
    }

    nodePtr insertNode = new Node(data);
    insertNode->next = indexNode->next;
    insertNode->prev = indexNode;
    indexNode->next->prev = insertNode;
    indexNode->next = insertNode;
}

void printForward(Node*& head) {
    nodePtr current = head;
    
    if (current->prev == nullptr){
        std::cout << "nullptr -> ";
    }
    
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }

    if (current == nullptr){
        std::cout << "nullptr" << std::endl;
    }
}



int main()
{
    nodePtr head = new Node(1);
    nodePtr tail;
    tail = head;
    
    insertNodeInFront(head, 2);
    insertNodeInFront(head, 3);
    insertNodeInFront(head, 4);
    insertNodeInFront(head, 6);
    
    printForward(tail);
    insertNodeAfterIndex(tail, 5, 3);
    printForward(tail);
}
