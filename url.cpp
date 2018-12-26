#include <iostream>
#include <string.h>
#include <stdbool.h>

using namespace std;

/*
Write a method to replace all spaces in a string with '%20  
You may assume that the string has sufficient space at the end to hold the additional 
characters, and that you are given the "true" length of the string. 
(Note: If implementing in Java,please use a character 
array so that you can perform this operation in place.)
EXAMPLE
Input: "Mr John Smith ", 13 
Output: "Mr%20John%20Smith"

*/

string urlFunc(string input)
{
    string output = "";

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            output += "%20";
        }
        else
        {
            output += input[i];
        }
    }
    return output;
}

int main()
{
    cout << urlFunc("Mr John Smith ") << endl;
    return 0;
}