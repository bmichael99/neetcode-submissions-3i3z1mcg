class Solution {
public:
    int climbStairs(int n) {
      if(n <= 2){
        return n;
      }

      vector<int> dp(n+1,0);
      dp[n-1] = 1; //1 way to reach the top from the last step, take 1 step
      dp[n-2] = 2; //2 ways to reach the last step from the second to last step, take 1 step and 1 step or take 2 steps.
      for(int i = n-3; i >= 0; i--){
        dp[i] = dp[i+1] + dp[i+2];
      }

      return dp[0];
    }


};