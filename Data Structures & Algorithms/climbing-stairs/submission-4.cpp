class Solution {
public:
    unordered_map<int,int> cache;
    int climbStairs(int n) {
      //bottom-up dp, TC: O(n) SC: O(n)
      //bottom- up dp (space optimized), TC: O(n) SC: O(1)
      // vector<int> dp(n+1,0);
      // dp[n] = 1; //if you're on the final step, there's 1 way to get here from already being here
      // dp[n-1] = 1; //if you're one step away from the top, there's 1 way to get to the top, climb 1 step
      int one = 1;
      int two = 1;

      for(int i = n-2; i >= 0; i--){
        int temp = one;
        one = two + one;
        two = temp;
      }
      return one;
    }

    //top-down memoization O(n)
    // int DFS(int i, int n) {
    //   if(i >= n){
    //     if(i == n){
    //       return 1;
    //     }
    //     return 0;
    //   }
    //   if(cache.contains(i)){
    //     return cache[i];
    //   }

    //   cache[i] = DFS(i+1,n) + DFS(i+2,n);
    //   return cache[i];
    // }
};