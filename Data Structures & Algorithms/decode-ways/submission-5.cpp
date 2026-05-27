class Solution {
public:
    unordered_map<int,int> cache;
    int numDecodings(string s) {
        //brute force is to generate all combinations of groups that can be decoded. O(2^n), where n is the length of the input string, 2 choices to either include 1 number or include 2 numbers. Tree is size n since the choice needs to be made for each input, so 2^n
        //Optimal is to memoize the brute force, this would be top-down dp.
        //better optimal is to just do dp bottom-up.  TC: O(n) SC: O(n)

        int n = s.length();
        vector<int> dp(n+1,0);

        dp[n] = 1;

        //working our way bottom-up, if we find a valid new path to decode, add 1 to the previous ways to decode (dp[i+1]);

        for(int i = n-1; i >= 0; i--){
          if(s[i] != '0'){
            dp[i] = dp[i+1]; //add number of ways to decode starting after curr index
          } else {
            continue;
          }

          if(i+1 < n && stoi(s.substr(i,2)) >= 1 && stoi(s.substr(i,2)) <= 26){
            dp[i] += dp[i+2]; //add number of ways to decode starting after group of 2
          }
        }
        return dp[0];

    }

    // take the input string and determine how many ways there are to decode it.
    // we can use 1 or 2 digits at a time, if it's 2 digits then we must be in the range of 1-26.
    // Never have leading 0's, any sub problem starting with a leading 0 is invalid. 0 can be the second number (10, 20)


    //memoized top-down DP, O(n), each sub problem is only solved once.
    // int DFS(int i, string s){
    //   if(i >= s.length()){ //finished decoding, base case. If there's an empty string, there is 1 way to decode that string.
    //     return 1;
    //   }
    //   if(s[i] == '0'){ //other base case, if leading 0 at current index then stop and return 0 ways to decode this.
    //     cache[i] = 0;
    //     return cache[i];
    //   }
    //   if(cache.contains(i)){
    //     return cache[i];
    //   }
    //   //valid if not 0
    //   cache[i] = DFS(i+1, s);

    //   //need to check that this number of length 2 is in the range of 1-26, and not a larger number.
    //   if(i+1 < s.length()){
    //     string length2 = s.substr(i,2);
    //     if(stoi(length2) >= 1 && stoi(length2) <= 26){
    //       cache[i] += DFS(i+2, s);
    //     }
    //   }

    //   return cache[i];
    // }



    // int DFS(int i, string s){
    //   if(i >= s.length()){ //finished decoding, base case. If there's an empty string, there is 1 way to decode that string.
    //     return 1;
    //   }
    //   if(s.substr(i,1) == "0"){ //other base case, if leading 0 at current index then stop and return 0 ways to decode this.
    //     return 0;
    //   }
    //   int ways = 0;
    //   //valid if not 0
    //   ways += DFS(i+1, s);

    //   //need to check that this number of length 2 is in the range of 1-26, and not a larger number.
    //   if(i+1 < s.length()){
    //     string length2 = s.substr(i,2);

    //     if(stoi(length2) >= 1 && stoi(length2) <= 26){
    //       ways += DFS(i+2, s);
    //     }
    //   }


    //   return ways;
    // }
};