class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int slowIndex = 0;
		int fastIndex;
		int sum = 0;
		int result = 0;
		for (fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
			sum += nums[fastIndex];
			while(sum >= target) {
				int minLength = fastIndex - slowIndex + 1;
				if (result == 0 || minLength < result)
					result = minLength;
				
				sum -= nums[slowIndex++];
			}
		}
		return result;
    }
};


/*    
