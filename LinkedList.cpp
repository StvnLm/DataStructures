#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtTheFront(Node*& head, int data) {
    // 1. Prepare new Node
    Node * newNode = new Node;
    newNode->data = data;
    // Put it infront of current head
    newNode->next = head; 
    // Move head PTR to point to the newNode
    head = newNode;
}

int main() {
    Node* head = nullptr;
    insertAtTheFront(head, 20);
    cout << head->data << endl;
    insertAtTheFront(head, 30);
    cout << head->data << endl;
}

