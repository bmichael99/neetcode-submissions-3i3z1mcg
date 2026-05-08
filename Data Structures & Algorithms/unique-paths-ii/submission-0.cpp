class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int ROWS = obstacleGrid.size();
      int COLS = obstacleGrid[0].size();
      if(obstacleGrid[ROWS-1][COLS-1] == 1) return 0; //if we cannot reach bottom right due to buttom right being an obstacle, return 0 possible unique paths
      if(obstacleGrid[0][0] == 1) return 0; //same with starting point

      vector<vector<long>> dp(ROWS+1, vector<long>(COLS+1,0));
      dp[ROWS-1][COLS-1] = 1;
      long right = 0;
      long below = 0;
      for(int r = ROWS-1; r >= 0; r--){
        for(int c = COLS-1; c>= 0; c--){
          right = 0;
          below = 0;
          if(c+1 != COLS)
            right = obstacleGrid[r][c+1] == 0 ? dp[r][c+1] : 0;
          if(r+1 != ROWS)
            below = obstacleGrid[r+1][c] == 0 ? dp[r+1][c] : 0;
          
          // if(obstacleGrid[r][c] != 1) we do not need this check since we only set right and below to valid places, so we'll never add calculated paths that are on invalid tiles. so basically the above checks make this check unnecessary.
            dp[r][c] += right + below;
        }
      }

      return dp[0][0];
    }
};