# 217. Contains Duplicate
[Contains Duplicate - LeetCode](https://leetcode.com/problems/contains-duplicate/description/)

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

## Brute Force
- Time Complexity = O(n^2)
- Space Complexity = O(1)

## Sorting
- Sort the array first, and then iterate the array and find if duplicated elements exist or not.

- Time Complexity = O(nlogn)
- Space Complexity = O(1)

## Hash Set or Hash Table
- Iterate the array
    - Find the element in the set, if the element exists in the set, it means there are duplicated elements.
    - Otherwise, insert the element into the set.

- Time Complexity = O(n)
- Space Complexity = O(n)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n_set;

        for (auto n : nums) {
            auto it = n_set.find(n);
            if (it != n_set.end()) return true;
            n_set.insert(n);
        }

        return false;
    }
};
```

### Optimized Version
- Insert all the elements into the hash set.
- Compare the size of the set with the size of the input array. If the size of the set is smaller, the input array contains duplicate.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n_set(nums.begin(), nums.end());
        if (n_set.size() < nums.size()) return true;
        return false;
    }
};
```