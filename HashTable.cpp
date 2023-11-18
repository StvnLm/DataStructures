#include <iostream>
using namespace std;

class Hash {
    
public:
    Hash()
    {
        for (int i = 0; i < tableSize; i++)
        {
            HashTable[i] = new item;
            HashTable[i]->name = "empty";
            HashTable[i]->drink = "empty";
            HashTable[i]->next = nullptr;
        }
    }
    
    int hash(string key) 
    {
        int index;
        int hash = 0;
        for (int i = 0; i < key.length(); i++) 
        {
            hash = hash + int(key[i]);
        }
        index = hash % tableSize;
        return index;
    }

    void addItem(string name, string drink) 
    {
        int index = hash(name);
        
        if (HashTable[index]->name == "empty")
        {
            HashTable[index]->name = name;
            HashTable[index]->drink = drink;
        }
        else 
        {
            item* ptr = HashTable[index];
            item* n = new item;
            n->name = name;
            n->drink = drink;
            n->next = nullptr;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    
    int numberOfItemsInIndex(int index)
    {
        int count = 0;

        if (HashTable[index]->name == "empty")
        {
            return count;
        }
        else
        {
            count++;
            item* ptr = HashTable[index];
            while (ptr->next != nullptr)
            {   
                count++;
                ptr = ptr->next;
            }
            return count;
        }
    }

    void printTable()
    {
    
    };

private:
    static const int tableSize = 10;
    
    struct item 
    {
        string name;
        string drink;
        item* next; 
    };
    
    item* HashTable[tableSize];
};

int main() 
{
    Hash myHash; // Create an instance of the Hash class
    myHash.addItem("Steven", "Milk Tea");
    std::cout << "Steven index = " << myHash.hash("Steven") << std::endl;
    myHash.addItem("Linda", "Water");
    std::cout << "Linda index = " << myHash.hash("Linda") << std::endl;
    myHash.addItem("Luna", "Water");
    std::cout << "Luna index = " << myHash.hash("Luna") << std::endl;
    myHash.addItem("Miso", "Orange Juice");
    std::cout << "Miso index = " << myHash.hash("Miso") << std::endl;
    std::cout << "Num of items in index = " << myHash.numberOfItemsInIndex(8) << std::endl;
    
    return 0;
}
