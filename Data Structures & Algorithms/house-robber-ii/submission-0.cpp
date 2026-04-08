class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        //houses are arranged in a circle. 
        //If you start with the first house then robbing the last house is never an option
        //If you start with the second house then you can rob the last house.
        int n = nums.size();
        return max(bottomUp(0,n-1,nums),bottomUp(1,n,nums));
    }

    int bottomUp(int start, int n, vector<int>& nums){ //use n as our end boundary in the array to account for houses being in a circle.
        

        vector<int> dp(n+1,0);
        dp[n] = 0;
        dp[n-1] = nums[n-1];

        for(int i = n-2; i >= start; i--){
            dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
        }

        return max(dp[start],dp[start+1]);
    }
};