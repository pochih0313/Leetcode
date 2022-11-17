# 1. Two Sum
[Two Sum - LeetCode](https://leetcode.com/problems/two-sum/)

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

## Brute Force
- Time Complexity = O(n^2)
- Space Complexity = O(1)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        for (int fast_index = 1; fast_index < nums.size(); fast_index++) {
            int slow_index = 0;
            while(slow_index < fast_index) {
                int sum = nums[slow_index] + nums[fast_index];
        
                if (sum == target) {
                    ans[0] = slow_index;
                    ans[1] = fast_index;
                    return ans;
                }
                
                slow_index++;
            }
        }
        
        return ans;
    }
};
```

## Hash map (one pass)
- Store value-index pair into hash table. When iterating, once target minus current value equals to the key in the hash table, return current index & the value to that key in the hash table (corresponding index).
  
- Time Complexity = O(n)
- Space Complexity = O(n)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_to_index_map;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (value_to_index_map.count(diff)) {
                return {value_to_index_map[diff], i};
            }
            
            value_to_index_map[nums[i]] = i;
        }
        
        return {};
    }
};
```

### Optimal
- No need to reaccess after searching for the key in the hash table

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_to_index_map;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            auto it = value_to_index_map.find(diff);
            if (it != value_to_index_map.end()) {
                return {it->second, i};
            }
            
            value_to_index_map[nums[i]] = i;
        }
        
        return {};
    }
};
```