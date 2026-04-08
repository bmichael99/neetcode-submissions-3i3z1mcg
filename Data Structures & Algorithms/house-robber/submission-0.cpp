class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }   

        //second approach where we either rob the current house and the houses starting 2 houses down. Or rob the houses starting from the adjacent house. choose the max between these two options.
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        dp[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
        }

        return max(dp[0],dp[1]);
    }
    
};