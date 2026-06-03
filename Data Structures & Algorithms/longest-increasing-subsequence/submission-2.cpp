class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //brute force: generate all possible subsequences, check which ones are strictly increasing and keep track of the longest. Could include pruning for paths aren't increasing, O(2^n)
        //Optimal DP: O(n^2). Each number keeps track of how many numbers are increasing larger than itself to the right of itself.


        int n = nums.size();
        vector<int> dp(n+1,1); //every val in dp should be set to 1 since each num is length of 1 on its own.
        dp[n] = 0;
        dp[n-1] = 1;
        int longest_subsequence = 1;

        for(int i = n-2; i >= 0; i--){
          for(int j = i+1; j < n; j++){
            if(nums[i] < nums[j]){
              dp[i] = max(1 + dp[j],dp[i]);
            }
          }
          longest_subsequence = max(dp[i],longest_subsequence);
        }

        return longest_subsequence;
    }
};