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
    {   item* ptr;
        for (int i = 0; i < tableSize; i++)
        {
            cout << "------------------------" << endl;
            cout << "Index = " << i << endl;
            ptr = HashTable[i];
            while (ptr != nullptr && HashTable[i]->name != "empty")
            {
                cout << ptr->name << endl;
                cout << ptr->drink << endl;
                ptr = ptr->next;
            }
        }
    };

    void findDrink(string name)
    {
        int index = hash(name);
        item* ptr;
        bool foundName = false;
        string drink;
        ptr = HashTable[index];
        
        while (ptr != nullptr)
        {
            if (ptr->name == name)
            {
                foundName = true;
                drink = ptr->drink;
            }
            ptr = ptr->next;
        }
        if (foundName == true)
        {
            cout << name << "'s favourite drink is " << drink << endl;
        }
        else
        {
            cout << name << "'s info was not found in the hash table" << endl;
        }
    }

    void removeItem(string name)
    {
        item* delPtr;
        item* p1;
        item* p2;
        int index = hash(name);
        
        if (HashTable[index]->name == "empty")
        {
            cout << name << " was not found in the hash table" << endl;
        }
        
        if (HashTable[index]->name == name && HashTable[index]->next == nullptr)
        {
            HashTable[index]->name = "empty";
            HashTable[index]->drink = "empty";
            HashTable[index]->next = nullptr;
            cout << name << " has been deleted from the hash table" << endl;
        }
        else if  (HashTable[index]->name == name && HashTable[index]->next != nullptr)
        {
            delPtr = HashTable[index];
            HashTable[index] = HashTable[index]->next;
            delete delPtr;
            cout << name << " has been deleted from the hash table" << endl;
        }
        else
        {
            p1 = HashTable[index]->next;
            p2 = HashTable[index];
            
            while (p1 != nullptr && p1->name != name)
            {
                p2 = p1;
                p1 = p1->next;
            }
            
            if (p1 == nullptr)
            {
                cout << name << " was not found in the hash table" << endl;
            }
            else 
            {
                delPtr = p1;
                p1 = p1->next;
                p2->next = p1;
                delete delPtr;
                cout << name << " has been deleted from the hash table" << endl;
            }
        }
    }

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
    myHash.addItem("Linda", "Water");
    myHash.addItem("Luna", "Water");
    myHash.addItem("Miso", "Orange Juice");
    myHash.findDrink("Steven");
    myHash.removeItem("Linda");
    myHash.printTable();
    
    return 0;
}
