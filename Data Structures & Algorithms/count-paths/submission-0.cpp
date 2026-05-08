class Solution {
public:
    int uniquePaths(int m, int n) {
      //bottom up
      vector<vector<int>> dp(m+1, vector<int>(n+1,0));
      
      dp[m-1][n-1] = 1;
      
      for(int r = m-1; r >= 0; r--){
        for(int c = n-1; c >= 0; c--){
          dp[r][c] += dp[r+1][c] + dp[r][c+1]; //use += here since we know each cell is 0 by default and we can make sure that dp[m-1][n-1] is 1 for the goal.
        }
      }

      return dp[0][0];
      
    }

  //Top Down memoization O(n+m)
  // int memoization(int r, int c, int ROWS, int COLS, vector<vector<int>>& cache){
  //   if(r < 0 || c < 0 || r == ROWS || c == COLS){
  //     return 0;
  //   }
  //   if(r == ROWS-1 && c == COLS-1){
  //     return 1;
  //   }
  //   if(cache[r][c] != -1){
  //     return cache[r][c];
  //   }

  //   cache[r][c] = memoization(r+1,c,ROWS,COLS,cache) +
  //   memoization(r,c+1,ROWS,COLS,cache);
  //   return(cache[r][c]);
  // }


    //brute force 2^(n+m)
    // int DFS(int r, int c, int ROWS, int COLS){
    //   if(r < 0 || c < 0 || r == ROWS || c == COLS){
    //     return 0;
    //   }
    //   if(r == ROWS-1 && c == COLS-1){
    //     return 1;
    //   }

    //   return(DFS(r+1,c,ROWS,COLS) +
    //   DFS(r,c+1,ROWS,COLS));
    // }
};