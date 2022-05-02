#include <iostream>

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
