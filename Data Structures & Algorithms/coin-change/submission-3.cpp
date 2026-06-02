class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      //bottom-up memoization. TC: O(n), SC: O(n). 
      //for each amount, calculate how many coins it takes to reach that amount. Loop through all coins and see if we can satisfy amount based on the coins we have available. If we can use a coin, then we know that the number of coins we used at the current amount is stored within dp, dp[a-coin]. We add to that count since we just used a coin to get there.


        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;

        for(int a = 0; a <= amount; a++){
          for(int& coin : coins){
            if(a >= coin){
              dp[a] = min(dp[a],1 + dp[a-coin]);
            }
          }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }

    //top-down memoization TC:O(n) SC:O(n)
    // int DFS(vector<int>& coins, int amount){
    //   if(amount <= 0){
    //     if(amount == 0){
    //       return 0;
    //     }
    //     return INT_MAX;
    //   }

    //   int minCount = INT_MAX;

    //   for(int& coin : coins){
    //     if(amount >= coin){
    //       int res = DFS(coins,amount-coin);
    //       if(res != INT_MAX){
    //         minCount = min(minCount, 1 + res);
    //       }
    //     }
    //   }
    //   return minCount;
    // }
};