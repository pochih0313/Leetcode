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
