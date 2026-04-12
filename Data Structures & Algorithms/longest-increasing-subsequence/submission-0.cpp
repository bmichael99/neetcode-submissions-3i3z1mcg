class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //naive approach is to generate all subsequences, see if it's strinctly increasing, and keep track of the longest subsequence. This could be done with backtracking in O(2^n) time complexity. This is very slow and an exponential time complexity. You would use backtracking to say to include or skip a number and generate all possible subsets

        //dp will keep track of the longest subsequence in relation to the current index. So if a number in front of index is larger than the current index, than that is one possible subsequence that we can join, and check if 1 + dp[j] is larger than currLongest, we want to store the longest possible subsequence from each index onwards into each dp[i] so that we don't have to repeat work for that index, we already know the longest subsequence from that index onwards. O(n^2)
        
        int n = nums.size();
        vector<int> dp(n,0);
        dp[n-1] = 1;
        int longest = 1;
        for(int i = n-2; i >= 0; i--){
            int currLongest = 1;
            for(int j = i+1; j < n; j++){
                if(nums[i] < nums[j]){
                    currLongest = max(currLongest, 1 + dp[j]);
                }
            }
            dp[i] = currLongest;
            longest = max(longest,currLongest);
        }
        return longest;
    }
};