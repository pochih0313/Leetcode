# 121. Best Time to Buy and Sell Stock
[Best Time to Buy and Sell Stock - LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Sliding Window
- when we need to consider the iterated element, we can use this technique.
- iterate the array, update the minimum price, and then calculate the profit and update the maximum profit.
  
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (auto price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        
        return max_profit;
    }
};
```