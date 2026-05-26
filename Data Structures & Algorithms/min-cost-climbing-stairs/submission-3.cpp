class Solution {
public:
    unordered_map<int,int> cache;
    int minCostClimbingStairs(vector<int>& cost) {
      //brute force, two choice DFS O(2^n)
      //memoized top-down DP, O(n)
      //optimal bottom-up DP, O(n)
      int n = cost.size();
      vector<int> dp(n+1,0);
      dp[n] = 0;
      dp[n-1] = cost[n-1];

      for(int i = n-2; i >= 0; i--){
        dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
      }
      return min(dp[0],dp[1]);
    }

    //top down DP, memoization, TC: O(n) SC: O(n) for recursion call stack
    // int DFS(int i, vector<int>& cost){
    //   if(i >= cost.size()){
    //     return 0;
    //   }
    //   if(cache.contains(i)){
    //     return cache[i];
    //   }
    //   cache[i] = cost[i] + min(DFS(i+1,cost), DFS(i+2,cost));
    //   return cache[i];
    // }
};