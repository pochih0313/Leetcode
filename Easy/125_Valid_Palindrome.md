# 125. Valid Palindrome
[Valid Palindrome - LeetCode](https://leetcode.com/problems/valid-palindrome/description/)

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Double Pointers
- Iterate the string and move the two pointer, if the 2 characters are alnumeric, make them lowercase and compare with each other. If 2 characters are different, return false. When the iteration finished, return true.
  
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) return true;
        
        int p1 = 0, p2 = s.size() - 1;
        
        while(p1 < p2) {
            while (p1 < p2 && !isalnum(s[p1])) p1++;
            while (p1 < p2 && !isalnum(s[p2])) p2--;
            
            if (tolower(s[p1]) != tolower(s[p2])) return false;
            
            p1++;
            p2--;
        }
        return true;
    }
};
```