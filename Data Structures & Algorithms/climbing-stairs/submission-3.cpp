class Solution {
public:
  
  int climbStairs(int n) {
    //bottom-up DP, O(n)
    vector<int> dp(n+1,0);
    dp[n] = 1;
    dp[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
      dp[i] = dp[i+1] + dp[i+2];
    }
    return dp[0];

  }
    
    //top down DP, O(n)
    // int ways(int i, int n){
    //   if(i >= n){
    //     if(i == n)
    //       return 1;
    //     return 0;
    //   }
    //   if(cache.contains(i)) return cache[i];

    //   cache[i] = ways(i+1,n) + ways(i+2,n);
    //   return cache[i];
    // }
};