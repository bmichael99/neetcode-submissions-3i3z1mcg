class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //brute force: generate all possible subsequences of each string and return the longest matching subsequence. O(2^n)
        //brute force v2: compare subsequence of text1 and text2, starting from the full string of each. If a character matches then we know we have a lcs of at least 1, and we can compare the remainder of each string starting after the letter that matches. If two letters don't match then we have two options/branches, of which we need to return the max of the two options/branches, those options are the remainder of text1 including the current letter and the remainder of text2 not including the current letter. The other option is the opposite aka the remainder of text1 not including the current letter and the remainder of text2 including the current letter. Example abcde ace. a's match so we can move to comparing bcde and ce. b and c don't match so we need to branch and calculate the LCS of cde ce and bcde e.

        //Optimal solution is basically to do brute force v2 within a 2D matrix, aka 2D dp. If two numbers match then we check the bottom right diagnal cell and say 1 + that number, that effectively allows us to say the first part of the brute force which is we add 1 + then compare the remainder of each string. If two numbers don't match then we take the max of the cell to the right and the cell below, which is same as the second part of the brute force where we take the max of the two branches explained in the paragraph above.

        int ROWS = text1.length();
        int COLS = text2.length();

        vector<vector<int>> dp(ROWS+1,vector<int>(COLS+1,0));

        for(int r = ROWS-1; r >= 0; r--){
            for(int c = COLS-1; c >= 0; c--){
                if(text1[r] == text2[c]){
                    dp[r][c] = 1 + dp[r+1][c+1];
                } else {
                    dp[r][c] = max(dp[r+1][c],dp[r][c+1]);
                }
            }
        }
        return dp[0][0];
    }
};