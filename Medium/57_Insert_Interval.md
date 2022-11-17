# 57. Insert Interval
[Insert Interval - LeetCode](https://leetcode.com/problems/insert-interval/)

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` *after the insertion*.

## Solution
### Original
- Time Complexity = O(n)
- Space Complexity = O(n)
    
```cpp
class Solution {
public:
    bool is_overlap(vector<int>& interval1, vector<int>& interval2) {
        return interval1[0] <= interval2[1] && interval1[1] >= interval2[0];
    }
    
    vector<int> merge(vector<int>& interval1, vector<int>& interval2) {
        vector<int> new_interval = {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
        return new_interval;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> new_intervals;
        if (intervals.size() == 0) {
            new_intervals.push_back(newInterval);
            return new_intervals;
        }
        
        
        int idx = 0;
        for (auto interval : intervals) {
            int cur_start = interval[0];
            int new_start = newInterval[0];
            
            if (new_start > cur_start) {
                new_intervals.push_back(interval);
                idx++;
                continue;
            }
            
            if (idx == 0) {
                new_intervals.push_back(newInterval);
                newInterval = interval;
                idx++;
                continue;
            }
            
            // overlap or not
            if (is_overlap(new_intervals.back(), newInterval)) {
                newInterval = merge(new_intervals.back(), newInterval);
                new_intervals.pop_back();
            }
            
            new_intervals.push_back(newInterval);
            newInterval = interval;

            idx++;
        }
        
        if (is_overlap(new_intervals.back(), newInterval)) {
            newInterval = merge(new_intervals.back(), newInterval);
            new_intervals.pop_back();
        }

        new_intervals.push_back(newInterval);
        
        return new_intervals;
    }
};
```
    
### Optimal (cleaner)
- 將interval重新放到new_intervals裡，考慮三個條件:
    - 當前interval的尾小於newInterval: 表示直接丟進new_intervals
    - 當前interval的頭大於newInterval: 表示丟newInterval，並把當前interval當為下一個要丟的newInterval
    - 若不符合上述兩種情況，表示出現overlap，這時只要將兩個interval做合併作為下一個要丟的newInterval，表示捨棄掉當前interval (已經合併)
- 最後把剩下的一個newInterval丟到new_intervals裡就完成
    
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        
        vector<vector<int>> new_intervals;

        for (auto interval : intervals) {
            if (interval[1] < newInterval[0]) {
                new_intervals.push_back(interval);
                continue;
            }
            
            if (interval[0] > newInterval[1]) {
                new_intervals.push_back(newInterval);
                newInterval = interval;
                continue;
            }
            
            newInterval = {min(interval[0], newInterval[0]), max(interval[1], newInterval[1])};
        }
            
        new_intervals.push_back(newInterval);
            
        return new_intervals;
    }
};
```
    
### Constant Space Complexity
- Time Complexity = O(n)
- **Space Complexity = O(1)**
    
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        int pos = lower_bound(begin(intervals), end(intervals), newInterval) - begin(intervals);
        
        intervals.insert(intervals.begin() + pos, newInterval);
        
        int j = 0;
        for(int i = 1;i <= n;i++){
            if(intervals[i][0] <= intervals[j][1])
            {
                intervals[j][0] = min(intervals[j][0], intervals[i][0]);
                intervals[j][1] = max(intervals[j][1], intervals[i][1]);
            }
            else{
                intervals[++j] = intervals[i];
            }
                
        }
        intervals.resize(j + 1);
        return intervals;
        
    }
};
``` 

### Most Elegant
https://leetcode.com/problems/insert-interval/discuss/21599/Elegant-C%2B%2B-STL-solution-using-%22equal_range%22-to-find-overlapped-intervals