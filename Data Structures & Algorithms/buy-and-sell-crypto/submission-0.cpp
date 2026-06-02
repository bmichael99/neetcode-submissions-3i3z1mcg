class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //keep track of the smallest number we've seen so far. We know that we buy a stock at some point and want to sell it in the future. So we always want to track the smallest number we've seen so far, subtract the current number from the min, and compare against max_profit
        //TC O(n) SC: O(1)

        int min_num = prices[0];
        int max_profit = 0;

        for(int i = 1; i < prices.size();i++){
          max_profit = max(max_profit,prices[i] - min_num);
          min_num = min(prices[i],min_num);
        }

        return max_profit;
    }
};