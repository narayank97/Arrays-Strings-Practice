#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;

// Runs in O(n^2)
// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures? 

bool isUnique(string myString)
{
  int Length = myString.length();
  for(int i = 0; i < Length; i++)
  {
    for(int j = 0; j < Length; j++)
    {
      if(i == j)
      {
        continue;
      }
      if(myString[i] == myString[j])
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  string name = "Kdog";
  string animal = "animal";
  string a = "aaaaaa";
  string b = "abcdef";

  cout << isUnique(name) << endl;
  cout << isUnique(animal) << endl;
  cout << isUnique(a) << endl;
  cout << isUnique(b) << endl;

  return 0;
}
