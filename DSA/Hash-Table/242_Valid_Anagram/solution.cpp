/*
Example:
s = apple
t = plepa
return true

s = apple
t = pllale
return false

Approach:
Hash Table

1. store all characters of s in a hash table
2. iterate string t, 
    and reduce the value of the key
3. iterate the whole hash table, if these is a value not equal to 0, return false
4. return true

*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool solution(string s, string t)
{
    unordered_map<char, int> table;
    for (auto c : s)
        table[c] += 1;

    for (auto c : t)
        table[c] -= 1;

    for (auto item : table) {
        if (item.second != 0) 
            return false;
    }

    return true;
}