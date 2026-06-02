class Solution {
public:
    int rob(vector<int>& nums) {
        //bottom-up dp, we can either rob the current house and the house 1 over, or rob starting from the adjacent house.
        //We want to keep track of the maximum amount of money we can rob.
        //since the houses are in a circle, if we rob the first house we can't rob the last house.
        //if we rob the second house, we can rob the last house.
        //maybe be some base case where we need to check just robbing the third house in the case where there are only 3 elements in nums
        //TC: O(n), SC: O(n)
        if(nums.size() == 1) return nums[0];

        int n = nums.size();

        return max(helper(0,n-1,nums),helper(1,n,nums)); //start either first or second house
    }

    int helper(int start, int end, vector<int> nums){
        int n = end;
        vector<int> dp(n+1,0);
        dp[n] = 0;
        dp[n-1] = nums[n-1];

        for(int i = n-2; i >= start; i--){
          dp[i] = max(nums[i] + dp[i+2], dp[i+1]); //we can either rob the current house and the house 1 over, or rob starting from the adjacent house.
        }

        return dp[start];
    }
};