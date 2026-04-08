class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;

        for(int amnt = 1; amnt <= amount; amnt++){
            for(int& coin : coins){
                if(coin <= amnt){
                    dp[amnt] = min(dp[amnt], 1 + dp[amnt-coin]);
                }
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};