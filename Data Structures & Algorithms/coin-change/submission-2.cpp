class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //brute force: generate all possible subsets with duplicates and keep track of minCoins and number of coins used. 
        //brute force TC: O(2^n) where n is the number of coins. SC: O(2^n) for recursion call stack
        //optimal: dp O(a * n) where a is amount. Work our way backwards 
        
      vector<int> dp(amount+1,amount+1); //max amount of coins we can use is amount if each coin was 1, amount+1 will always be above the max amount of coins we can use.
      dp[0] = 0;

      for(int a = 0; a <= amount; a++){
        for(int& coin : coins){
          if(coin <= a){
            dp[a] = min(dp[a], 1 + dp[a - coin]);
          }
        }
      }

      return dp[amount] == amount+1 ? -1 : dp[amount];
    }

    //top-down dp is a memoized backtracking solution where whenever we use a coin we subtract from amount the coin value and increase our result by 1. Our base case is returning 0 when the amount is 0. If our amount is 1 and we have a coin of value 1 then we can use 1 coin to get rid of that amount and get us to 0. resulting in a minCount of 1 since we know we use 1 coin for 1 amount.

    // int backTracking(vector<int>& coins, int amount){
    //   if(amount <= 0){
    //     if(amount == 0){
    //       return 0;
    //     }
    //     return INT_MAX;
    //   }

    //   int minCount = INT_MAX;
    //   for(int& coin : coins){
    //     if(coin <= amount){
    //       int res = backTracking(coins,amount - coin);
    //       if(res != INT_MAX)
    //         minCount = min(minCount, 1 + res);
    //     }
    //   }

    //   return minCount;
    // }
};