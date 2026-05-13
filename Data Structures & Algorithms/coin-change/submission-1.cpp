class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      //naive solution is to generate all possible subsets that equal to 11 and choose the subset with the least amount of coins O(2^n)
      //optimal solution   
      int n = coins.size();
      vector<long> dp(amount+1,INT_MAX);
      dp[0] = 0; //to get an amount of 0 we need 0 coins

      for(int i = 1; i <= amount; i++){
        for(int& coin: coins){
          if(i >= coin){
            dp[i] = min(dp[i],1 + dp[i-coin]); //use 1 coin and check how many coins it took at the amount - the coin we just used. We want to compare against all possible coins we can use so get the min().
          }
        }
      }
      return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

};