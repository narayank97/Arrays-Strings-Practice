#include <iostream>
#include <string.h>
#include <stdbool.h>

 // O(N)
 // BEST SOLUTION TO FIND IF STRING IS UNIQUE;

using namespace std;

bool isUniqueChars(string str) {
   
   int* mycheck = new int[26];
   int index = 0;
   memset(mycheck,0,26); // created an array of size 26  for each letter in alphabet
  
   for(int i = 0; i < str.length(); i++) // initialize each element to 0
   {
        index = 0; // THIS CHUNK USED TO make cpaital letters lowercase ///////
        if(str[i] < 97)
        {
            str[i] += 32;
        }
        index = str[i] - 97;/////////////////////////////////////////////////////


        mycheck[index]++; // increment ascii position
        if(mycheck[index] > 1) // this indicates that there is more then 1 ascii char
        {
            return false;
        }
   }
   return true;
}

int main()
{
    cout << isUniqueChars("Karun") << endl;
    cout << isUniqueChars("abca") << endl;
    
    return 0;
}