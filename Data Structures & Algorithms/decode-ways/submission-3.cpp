class Solution {
public:
//Bottom Up DP, memoization O(n)
    int numDecodings(string s) {
      //generate all possible combinations of ways to decode a message
      //we only need to return the number of ways a message can be decoded
      //two choices, include just the current number, or also include the next number if it's a valid two digit number (10-26) and it doesn't start with 0
      int n = s.length();
      vector<int> dp(n+1,0);
      dp[n] = 1;

      for(int i = n-1; i >= 0; i--){
        if(s[i] == '0'){
          dp[i] = 0; //redundant
          continue;
        }

        dp[i] = dp[i+1];

        if(i+1 < n){
          int num = stoi(s.substr(i,2));
          if(num >= 10 && num <= 26){
            dp[i] += dp[i+2]; //if a grouping of two letters is a valid decode, then add the number of ways the number can be decoded including this new decoding.
          }
        }
      }

      return dp[0];
    }

// //Top Down DP, memoization O(n)
//     int numDecodings(string s) {
//       //generate all possible combinations of ways to decode a message
//       //we only need to return the number of ways a message can be decoded
//       //two choices, include just the current number, or also include the next number if it's a valid two digit number (10-26) and it doesn't start with 0
//       vector<int> cache(s.length(),-1);
//       return DFS(0,s,cache);
//     }

//     int DFS(int i, string& s, vector<int>& cache){
//       if(i >= s.length()){
//         return 1;
//       }
//       if(s[i] == '0'){
//         return 0;
//       }
//       if(cache[i] != -1) return cache[i];

//       //choose one number
//       cache[i] = DFS(i+1,s,cache);

//       //choose two numbers
//       if(i+1 < s.length()){
//         int num = stoi(s.substr(i,2));
//         if(num >= 10 && num <= 26){
//           cache[i] += DFS(i+2,s,cache);
//         }
//       }
//       return cache[i];
//     }

    // //brute force: bottom-up recursion, O(2^n)
    // int numDecodings(string s) {
    //   //generate all possible combinations of ways to decode a message
    //   //we only need to return the number of ways a message can be decoded
    //   //two choices, include just the current number, or also include the next number if it's a valid two digit number (10-26) and it doesn't start with 0
    //   return DFS(0,s);
    // }

    // int DFS(int i, string& s){
    //   if(i >= s.length()){
    //     return 1;
    //   }
    //   if(s[i] == '0'){
    //     return 0;
    //   } 

    //   //choose one number
    //   int ways = DFS(i+1,s);

    //   //choose two numbers
    //   if(i+1 < s.length()){
    //     int num = stoi(s.substr(i,2));
    //     if(num >= 10 && num <= 26){
    //       ways += DFS(i+2,s);
    //     }
    //   }
    //   return ways;
    // }


};