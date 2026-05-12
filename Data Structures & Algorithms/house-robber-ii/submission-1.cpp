class Solution {
public:
//Bottom Up DP O(n)
  int rob(vector<int>& nums) {
    //same as house robber 1 but now the houses are in a circle.
    //basically if we rob the first house we're not allowed to rob the last house
    //if we rob the second house we can rob the last house
    if(nums.size() == 1) return nums[0];
    int n = nums.size();
    
    return max(BottomUp(0, n-1, nums), BottomUp(1, n, nums));
  }

  int BottomUp(int start, int n, vector<int>& nums){
    vector<int> dp(n+1,0);
    dp[n] = 0;
    dp[n-1] = nums[n-1];

    for(int i = n-2; i >= start; i--){
      dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
    }

    return max(dp[0],dp[1]);
  }

  //memoization O(n)
  // int rob(vector<int>& nums) {
  //   //same as house robber 1 but now the houses are in a circle.
  //   //basically if we rob the first house we're not allowed to rob the last house
  //   //if we rob the second house we can rob the last house
  //   if(nums.size() == 1) return nums[0];
  //   vector<int> cache(nums.size(),-1);
  //   vector<int> cache2(nums.size(),-1);
    
  //   return max(DFS(0,nums.size()-1,nums, cache), DFS(1,nums.size(),nums, cache2));
  // }

  // int DFS(int i, int n, vector<int>& nums, vector<int>& cache){
  //   if(i >= n){
  //     return 0;
  //   }
  //   if(cache[i] != -1) return cache[i];
  //   //can either rob the current house and houses starting 2 houses down, or rob houses starting from 1 house down (the adjacent house)
  //   cache[i] = max(nums[i] + DFS(i+2,n,nums,cache), DFS(i+1,n,nums,cache));
  //   return cache[i];
  // }
};