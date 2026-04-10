class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1,false);
        dp[n] = true;


        for(int i = n-1; i >= 0; i--){
            for(string& word : wordDict){
                if(s.substr(i,word.length()) == word){
                    dp[i] = dp[i + word.length()];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};
