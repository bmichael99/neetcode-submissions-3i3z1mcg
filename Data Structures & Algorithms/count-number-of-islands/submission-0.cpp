class Solution {
public:
    int ROWS;
    int COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        
        // vector<vector<bool>> visited(ROWS, vector<bool>(COLS,false));
        int count = 0;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == '1'){
                    DFS(r,c,grid);
                    count++;
                }
            }
        }
        return count;
    }

    //change all land to water for all connected land.
    void DFS(int r, int c, vector<vector<char>>& grid){
        if(r < 0 || c < 0 || r == ROWS || c == COLS || grid[r][c] == '0'){
            return;
        }
        
        grid[r][c] = '0';
        DFS(r+1, c, grid);
        DFS(r-1, c, grid);
        DFS(r, c+1, grid);
        DFS(r, c-1, grid);
    }
};