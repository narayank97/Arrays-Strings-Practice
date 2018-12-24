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
        hash += ((int) key[i]) * 17;
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

void Hash::findDrink(string name)
{
    int index = hashFunc(name); // calculates which linked list name is in
    bool foundName = false;
    string drink;

    item* PTR = hashTable[index];
    while(PTR != NULL) // keep going through Linked List until name is found
    {
        if(PTR -> name == name)
        {
            foundName = true;
            drink = PTR -> drink;
        }
        PTR = PTR -> nextItem;
    }
    if(foundName == true)
    {
        cout << "Favorite Drink = " << drink << endl;
    }
    else
    {
        cout << "That info was not found." << endl;
    }
}

void Hash::removeItem(string name)
{
    // 4 different cases of REMOVAL
    // CASE 1: Linked List is empty
    // CASE 2: 1 item in LL and that item == name
    // CASE 3: name located as 1st in LL and more items in LL
    // CASE 4: LL has items but name is not first one
    // CASE 4.1: no match
    // CASE 4.2: match is found

    int index = hashFunc(name); // calculates which linked list name is in
    item* delPTR;
    item* P1;
    item* P2;

     // CASE 1: Linked List is empty
    if(hashTable[index] -> name == "empty" && hashTable[index] -> nextItem == NULL)
    {
        cout << name << " this name was not found." << endl;
    }

    // CASE 2: 1 item in LL and that item == name
    else if(hashTable[index] -> name == name && hashTable[index] -> nextItem == NULL)
    {
        hashTable[index] -> name = "empty";
        hashTable[index] -> drink = "empty";
        cout << name << " was removed from Hash Table." << endl;
    }

    // CASE 3: name located as 1st in LL and more items in LL
    else if(hashTable[index] -> name == name)
    {
        delPTR = hashTable[index];
        hashTable[index] = hashTable[index] -> nextItem;
        delete delPTR;
        cout << name << " was removed from Hash Table." << endl;
    }

    // CASE 4: LL has items but name is not first one
    // CASE 4.1: no match
    // CASE 4.2: match is found
    else
    {
        P1 = hashTable[index] -> nextItem;
        P2 = hashTable[index];

        while(P1 != NULL && P1 -> name != name)
        {
            P2 = P1;
            P1 = P1 -> nextItem;
        }
        // CASE 4.1: no match
        if(P1 == NULL)
        {
            cout << name << " this name was not found." << endl;
        }
        // CASE 4.2: match is found
        else
        {
            delPTR = P1;
            P1 = P1 -> nextItem;
            P2 -> nextItem = P1;
            delete delPTR;
            cout << name << " was removed from Hash Table." << endl;
        }
    }




} 

int main()
{
    string name = "";
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

    myHashTable.printTable();

    while(name != "exit")
    {
        cout << "Remove: ";
        cin >> name;
        if(name != "exit")
        {
            myHashTable.removeItem(name);
            myHashTable.printTable();
        }
    }
    return 0;
}