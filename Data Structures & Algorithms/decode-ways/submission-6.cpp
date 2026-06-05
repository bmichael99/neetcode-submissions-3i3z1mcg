class Solution {
public:
    unordered_map<int,int> cache;
    int numDecodings(string s) {
      //You can either use 1 number or two numbers, can never use the number 0 leading. prune paths that start with 0. 2^n combinations problem brute force. Optimized to O(n) with memoization and sub problem can be converted to bottom-up DP



      int n = s.length();
      vector<int> dp(n+1,0);
      dp[n] = 1;

      for(int i = n-1; i >= 0; i--){
        if(s[i] == '0') continue;
        dp[i] = dp[i+1];

        if(i+1 < s.length()){
          string decoded = s.substr(i,2);

          if(stoi(decoded) >= 1 && stoi(decoded) <= 26){
            dp[i] += dp[i+2];
          }
        }
      }
      return dp[0];
    }

    // int DFS(int i, string& s){
    //   if(i >= s.length()){
    //     return 1;
    //   }
    //   if(s[i] == '0'){
    //     return 0;
    //   }
    //   if(cache.contains(i)){
    //     return cache[i];
    //   }

    //   cache[i] += DFS(i+1,s);;


    //   if(i+1 < s.length()){
    //     string decoded = s.substr(i,2);
    //     if(stoi(decoded) >= 1 && stoi(decoded) <= 26){
    //       cache[i] += DFS(i+2,s);
    //     }
    //   }

      
    //   return cache[i];
    // }
};