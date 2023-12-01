/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* leftPtr;
    Node* rightPtr;
    
    Node(int k) : key(k), leftPtr(nullptr), rightPtr(nullptr) {}
};

class BinarySearchTree {
    
    private:
        Node* rootPtr;
    
    public:
        BinarySearchTree() : rootPtr(nullptr) {}
        
        void insert(int key) {
            rootPtr = insertRecursive(rootPtr, key);
        }
        
        Node* insertRecursive(Node* rootPtr, int key) {
            if (rootPtr == nullptr) {
                return new Node(key);
            }
            
            if (key < rootPtr->key) {
                rootPtr->leftPtr = insertRecursive(rootPtr->leftPtr, key);
            }
            else if (key > rootPtr->key) {
                rootPtr->rightPtr = insertRecursive(rootPtr->rightPtr, key);
            }
            return rootPtr;
        }
        
        bool search(int key) {
            return searchRecursive(rootPtr, key);
        }
        
        bool searchRecursive(Node* rootPtr, int key) {
            if (rootPtr == nullptr) {
                return false; // key not found
            }
            
            if (rootPtr->key == key) {
                return true; //key is root 
            }
            
            if (key < rootPtr->key) {
                return searchRecursive(rootPtr->leftPtr, key);
            }
            else {
                return searchRecursive(rootPtr->rightPtr, key);
            }
        }
};

int main()
{
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(5);
    tree.insert(9);
    
    for (int i = 0; i < 10; i++) {
        bool found = tree.search(i);
        if (found) {
            std::cout << "Found " << i << " in the tree." << std::endl;
        }
        else {
            std::cout << "Not found " << i << " in the tree." << std::endl;
        }
    }

    return 0;
}
