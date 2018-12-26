#include <iostream>
#include <string.h>
#include <stdbool.h>

using namespace std;

// Given two strings,write a method to decide if one is a permutation of the other.

int indexGen(char letter)
{
    int index;
    index = 0; // THIS CHUNK USED TO make cpaital letters lowercase
    int myLetter = (int) letter;
    if(myLetter < 97)
    {
        myLetter += 32;
    }
    return index = myLetter - 97;

}

bool permCheck(string word1, string word2) 
{
    int* myWord1 = new int[26];
    int* myWord2 = new int[26];

    memset(myWord1,0,26);
    memset(myWord2,0,26);

    int indexWord1 = 0;
    int indexWord2 = 0;


    if(word1.length() != word2.length())
    {
        return false;
    }
    
    for(int i = 0; i < word1.length(); i++) // initialize each element to 0
    {
        indexWord1 = 0;
        indexWord2 = 0;
        indexWord1 = indexGen(word1[i]);
        indexWord2 = indexGen(word2[i]);
        myWord1[indexWord1]+=1;
        myWord2[indexWord2]+=1;
    }
    for(int j = 0; j < 26; j++)
    {
        if(myWord1[j] != myWord2[j])
        {
            return false;
        }
        continue;
    }
    return true;
   
}


int main()
{
    cout << permCheck("karun","naruk") << endl;
    cout << permCheck("abc","deg") << endl;
    return 0;
}
