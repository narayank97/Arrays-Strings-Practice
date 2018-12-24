#include <iostream>
#include <string.h>

using namespace std;

class Hash
{
    private:
        static const int tableSize = 4;
        struct item // things the hashtable consists of
        {
            string name;
            string drink;
            item* nextItem;

        };
        item* hashTable[tableSize]; // creation of the actual hash table
    public:
        Hash();
        int hashFunc(string key); 
        void addItem(string name, string drink);
        int numberOfInputsInIndex(int index);
        void printTable();
        void printLinkedLists(int index);
        void findDrink(string name);
        void removeItem(string name);
};