#include <iostream>
#include <string.h>
#include "hash.h"

using namespace std;

Hash::Hash() // constructor
{
    for(int i = 0; i < tableSize; i++) // initilize each index
    {
        hashTable[i] = new item;
        hashTable[i] -> name = "empty";
        hashTable[i] -> drink = "empty";
        hashTable[i] -> nextItem = NULL;
        
    }
}

int Hash::hashFunc(string key)
{
    int hash = 0;
    int index;
    int mylength = key.length();
    for(int i = 0; i < mylength; i++)
    {
        hash += (int) key[i];
    }
    index = hash % tableSize;
    return index;

}

void Hash::addItem(string name, string drink)
{
    int index = hashFunc(name);
    if(hashTable[index] -> name == "empty")
    {
        hashTable[index] -> name = name;
        hashTable[index] -> drink = drink;
    }
    else // if the index is occupied we create a new item, then go through LL to find open spot
    {
        item* PTR = hashTable[index];
        item* newInput = new item;
        newInput -> name = name;
        newInput -> drink = drink;
        newInput -> nextItem = NULL;
        
        while(PTR -> nextItem != NULL) // loops through Linked List
        {
            PTR = PTR -> nextItem;
        }
        PTR -> nextItem = newInput; // found open spot, becomes its home
    }
}

int Hash::numberOfInputsInIndex(int index)
{
    int count = 0;
    if(hashTable[index] -> name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* myPosition = hashTable[index];
        while(myPosition -> nextItem != NULL)
        {
            count++;
            myPosition = myPosition -> nextItem;
            
        }
        return count;
    }
}

void Hash::printTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = numberOfInputsInIndex(i);
        cout << "---------------" << endl;
        cout << "index = " << i << endl;
        cout << hashTable[i] -> name<< endl;
        cout << hashTable[i] -> drink<< endl;
        cout << "number of item = " << number<< endl;
        cout << "---------------" << endl;
    }

}

void Hash::printLinkedLists(int index)
{
    item* PTR = hashTable[index];

    if(PTR -> name == "empty")
    {
        cout << "index = " << index << " is empty." << endl;
    }
    else
    {
        cout << "index = " << index << " contains all of the following" << endl;
        while(PTR != NULL)
        {
            cout << "---------------" << endl;
            cout << PTR -> name<< endl;
            cout << PTR -> drink<< endl;
            cout << "---------------" << endl;
            PTR = PTR -> nextItem;

        }
    }

}

int main()
{
    Hash myHashTable;
    
    myHashTable.addItem("Karun","beer");
    myHashTable.addItem("vdawg","wine");
    myHashTable.addItem("mom","water");
    myHashTable.addItem("tran","air");
    myHashTable.addItem("ching","coke");
    myHashTable.addItem("trish","milkshake");
    myHashTable.addItem("david","chesse milk");
    myHashTable.addItem("Kris","vodka");
    myHashTable.addItem("rob","powerade");
    myHashTable.addItem("jay","grog");
    myHashTable.addItem("tan","caprisun");
    myHashTable.addItem("john","juice");

    myHashTable.printLinkedLists(2);
    cout << endl;
    myHashTable.printTable();

    return 0;
}