class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int result = INT_MAX;
		int arraySize = nums.size();
		
		int sum[arraySize];
		sum[0] = nums[0];
		for (int i = 1; i < arraySize; i++)
			sum[i] = sum[i-1] + nums[i];
		
		for (int index = 0; index < arraySize; index++) {
			int lowIndex = index;
			int highIndex = arraySize - 1;
			while(lowIndex <= highIndex) {
				int midIndex = lowIndex + (highIndex - lowIndex) / 2;
				int s = index != 0 ? (sum[midIndex] - sum[index-1]) : sum[midIndex];
				if (s >= target){
					highIndex = midIndex - 1;
					result = min(result, (midIndex - index +1));
				} else {
					lowIndex = midIndex + 1;
				}
			}
		}

		return result != INT_MAX ? result : 0;
    }
};
