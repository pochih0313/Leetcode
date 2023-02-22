# 704. Binary Search
[Binary Search - LeetCode](https://leetcode.com/problems/binary-search/)

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

## Iteration
- Time: O(log n)
- Space: O(1)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
            int lowIndex = 0;
            int highIndex = nums.size()-1;
    
            while(lowIndex <= highIndex) {
                int midIndex = lowIndex + (highIndex - lowIndex) / 2; // prevenet overflow
                
                if (target == nums[midIndex])
                    return midIndex;
                if (target < nums[midIndex])
                    highIndex = midIndex - 1;
                else
                    lowIndex = midIndex + 1;
            }
            
            return -1;
    }
};
```

## Recursion
- Time: O(log n)
- Space: O(log n)

```cpp
class Solution {
public:
    int recursive(vector<int>& nums, int target, int low, int high) {
        int mid = low + (high - low) / 2;

        if (low > high)
            return -1;
        if (target == nums[mid])
            return mid;
        if (target < nums[mid])
            return recursive(nums, target, low, mid-1);
        else
            return recursive(nums, target, mid+1, high);
    }
    int search(vector<int>& nums, int target) {
        return recursive(nums, target, 0, nums.size()-1); 
    }
};
```
    
## Discussion
- Iterative > Recursive: space complexity is better because the recursive method uses stack.