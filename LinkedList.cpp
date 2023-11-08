#include <iostream>

using namespace std;

struct Node {
    int data; 
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};


void insertInfrontOfHead(Node*& head, int data) {
    Node* tmp;
    tmp = new Node(data);
    tmp->next = head;
    head = tmp;
}


int countNodes(Node*& head) {
    int count = 0;
    Node* cursor = head;
    while (cursor != nullptr) {
        count++;
        cursor = cursor->next;
    }
    return count;
}

int main()
{
    Node* listHead = nullptr;
    insertInfrontOfHead(listHead, 10);
    insertInfrontOfHead(listHead, 20);
    insertInfrontOfHead(listHead, 30);
    Node* cursor = listHead;
    
    while (cursor != nullptr) {
        std::cout << cursor->data << "-->";
        cursor = cursor->next;
    }
        std::cout << "nullptr" << std::endl;
    
    std::cout << "Number of nodes: " << countNodes(listHead) << std::endl;
    
    // Don't forget to free the memory allocated for the node
    while (listHead != nullptr) {
        Node* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }
        
    return 0;
}
