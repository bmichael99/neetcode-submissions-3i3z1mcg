class Solution {
public:
    int ROWS;
    int COLS;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for(int r = 0; r < ROWS;r++){
            for(int c = 0; c < COLS;c++){
                if(grid[r][c] == 1){
                    maxArea = max(maxArea, DFS(r,c,grid));
                }
            }
        }

        return maxArea;
    }

    int DFS(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r == ROWS || c == COLS || grid[r][c] == 0){
            return 0;
        }

        grid[r][c] = 0;
        int size = 0;
        size += DFS(r+1,c,grid);
        size += DFS(r-1,c,grid);
        size += DFS(r,c+1,grid);
        size += DFS(r,c-1,grid);

        return size + 1; //if we're at a valid grid of land then we add 1 to size. Or perhaps a better way to say this is that we're not at an invalid piece of land.
    }
};