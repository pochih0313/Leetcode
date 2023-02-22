# 242. Valid Anagram
[Valid Anagram - LeetCode](https://leetcode.com/problems/valid-anagram/)

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Hash Table
- Time: O(n)
- Space: O(1)

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
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
};
```

### Optimal
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> table;
        for (int i = 0; i < s.size(); i++) {
            table[s[i]] += 1;
            table[t[i]] -= 1;
        }

        for (auto e : table) {
            if (e.second != 0) return false;
        }
        
        return true;
    }
};
```


