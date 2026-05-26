class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp problem
        //each number records how many numbers were larger relative to itself to the right of itself in the array
        //find the first number that's larger and see how many numbers are larger than that number, add 1. keep track of longest

        int longest_inc_subsequence = 0;
        int n = nums.size();
        vector<int> dp(n,0);

        for(int i = n-1; i >= 0; i--){
          int curr_longest = 0;
          for(int j = i+1; j < n; j++){
            if(nums[i] < nums[j]){
              curr_longest = max(curr_longest,dp[j]);
            }
          }
          dp[i] = 1 + curr_longest;
          longest_inc_subsequence = max(dp[i], longest_inc_subsequence);
        }
        return longest_inc_subsequence;
    }
};