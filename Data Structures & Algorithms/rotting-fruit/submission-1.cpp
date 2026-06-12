class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int,int>> bfs;
        int fresh_oranges = 0;

        for(int r = 0; r < ROWS; r++){
          for(int c = 0; c < COLS; c++){
            if(grid[r][c] == 2){
              bfs.push({r,c});              
            }
            else if(grid[r][c] == 1){
              fresh_oranges++;
            }
          }
        }
        if(fresh_oranges == 0) return 0;
        int minutes = 0;
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!bfs.empty()){
          int n = bfs.size();

          for(int i = 0; i < n;i++){
            int r = bfs.front().first;
            int c = bfs.front().second;
            bfs.pop();

            for(vector<int>& dir : directions){
              int rd = r + dir[0];
              int cd = c + dir[1];

              //only spread to fresh oranges, do not go out of bounds.
              if(rd < 0 || cd < 0 || rd == ROWS || cd == COLS || grid[rd][cd] != 1){
                continue;
              }
              grid[rd][cd] = 2; //make the fresh orange rotten.
              fresh_oranges--;
              bfs.push({rd,cd});
            }
          }
          minutes++;
        }

      //subtract minutes by 1 because the bfs loop will always loop an extra time after all oranges are rotten.
      return fresh_oranges == 0 ? minutes-1 : -1;
    }
};