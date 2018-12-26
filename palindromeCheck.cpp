#include <iostream>
#include <string.h>
#include <stdbool.h>

using namespace std;

/*
Palindrome Permutation: Given a string, write a function to check if 
it is a permutation of a palin­ drome. A palindrome is a word or phrase 
that is the same  rwards and backwards. A permutation is a rearrangement 
of letters. The palindrome does not need to be limited to just dictionary words.

EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat", "atco eta", etc.)
*/

bool palindromeCheck(string myInput)
{
    int index = 0;
    int* myCheck = new int[26];
    memset(myCheck,0,26);
    int countOf1 = 0;

    for(int i = 0; i < myInput.length(); i++)
    {
        index = 0;
        if(myInput[i] < 97)
        {
            myInput[i] += 32;
        }
        index = myInput[i] - 97;
        if(myCheck[index] == 0)
        {
            myCheck[index]++;
        }
        else if(myCheck[index] == 1)
        {
            myCheck[index]--;
        }
    }
    countOf1 = 0;
    for(int j = 0; j < 26; j++)
    {
        if(myCheck[j] == 1)
        {
            countOf1++;
        }
        if(countOf1 > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << palindromeCheck("aab") << endl;
    cout << palindromeCheck("abcdef") << endl;
    return 0;
}