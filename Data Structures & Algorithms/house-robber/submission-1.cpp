class Solution {
public:
  //Bottom Up DP O(n)
  int rob(vector<int>& nums) {
      //rob the most amount of money, but cannot rob adjacent houses
      //we can choose to either rob the second house or the third house (skip 1 or skip 2)
      //you could also say, we either rob the current house and the houses starting 2 houses down. Or rob the houses starting from the adjacent house. choose the max between these two options.
    int n = nums.size();
    vector<int> dp(n+1,0);
    dp[n] = 0;
    dp[n-1] = nums[n-1];

    for(int i = n-2; i >= 0; i--){
      dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
    }
    return max(dp[0],dp[1]);
  }


  // //Top Down DP Memoization O(n)
  // int rob(vector<int>& nums) {
  //     //rob the most amount of money, but cannot rob adjacent houses
  //     //we can choose to either rob the second house or the third house (skip 1 or skip 2)
  //     vector<int> cache(nums.size(),-1);
  //     return max(DFS(0,nums,cache),DFS(1,nums,cache));
  // }

  // int DFS(int i, vector<int>& nums, vector<int>& cache){
  //   if(i >= nums.size()){
  //     return 0;
  //   }
  //   if(cache[i] != -1){
  //     return cache[i];
  //   }

  //   cache[i] = nums[i] + max(DFS(i+2,nums,cache),DFS(i+3,nums,cache));
  //   return cache[i];
  // }

  // bottom up recursion O(2^n)
  // int rob(vector<int>& nums) {
  //     //rob the most amount of money, but cannot rob adjacent houses
  //     //we can choose to either rob the second house or the third house (skip 1 or skip 2)
  //     return max(DFS(0,nums),DFS(1,nums));
  // }

  // int DFS(int i, vector<int>& nums){
  //   if(i >= nums.size()){
  //     return 0;
  //   }

  //   int money = nums[i] + max(DFS(i+2,nums),DFS(i+3,nums));
  //   return money;
  // }

  
};