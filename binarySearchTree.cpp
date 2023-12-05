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
        

        
        int findMin(){
            if (rootPtr == nullptr){
                std::cout << "Tree is empty" << std::endl;
                return 0;
            }

            // Traverse to the left-most Node
            Node* cursor = rootPtr;
            while (cursor->leftPtr != nullptr){
                cursor = cursor->leftPtr;
            }
            
            return cursor->key;
            
        };
        
        int findMax(){
            if (rootPtr == nullptr){
                std::cout << "Tree is empty" << std::endl;
                return 0;
            }

            // Traverse to the right-most Node
            Node* cursor = rootPtr;
            while (cursor->rightPtr != nullptr){
                cursor = cursor->rightPtr;
            }
            
            return cursor->key;
            
        };
        
        // void remove(int key){};
        
        int getHeightOfTree() {
            return getHeight(rootPtr); // Call getHeight starting from the root
        }
        
        int getHeight(Node* nodePtr){
            if (nodePtr == nullptr){
                return 0;
            }
            else {
                int leftHeight = getHeight(nodePtr->leftPtr);
                int rightHeight = getHeight(nodePtr->rightPtr);
                return 1 + std::max(leftHeight, rightHeight);
            }
        };
        
        // void inOrderTraversal(){};
        
        // void preOrderTraversal(){};
        
        // void postORderTraversal(){};
        
};

int main()
{
    BinarySearchTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(50);
    tree.insert(60);
    tree.insert(5);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    // std::cout << tree.findMax() << std::endl;
    // std::cout << tree.findMin() << std::endl;
    std::cout << tree.getHeightOfTree() << std::endl;
    // for (int i = 0; i < 10; i++) {
    //     bool found = tree.search(i);
    //     if (found) {
    //         std::cout << "Found " << i << " in the tree." << std::endl;
    //     }
    //     else {
    //         std::cout << "Not found " << i << " in the tree." << std::endl;
    //     }
    // }

    return 0;
}
