class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //add all rotten oranges to the queue, from each point of the queue spread out and rot neighboring fresh oranges, adding those to the queue, continue until all is rotten. Each loop of a layer of the queue is a minute.
        if(grid.empty() || grid[0].empty()){
            return 0;
        }

        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int,int>> q;
        int freshCount = 0;

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS;c++){
                if(grid[r][c] == 1){
                    freshCount++;
                }
                if(grid[r][c] == 2){
                    q.push({r,c});
                }
            }
        }
        if(freshCount == 0){
            return 0;
        }
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int minutes = 0;
        while(!q.empty()){
            //loop through current layer from each rotten orange
            int curr = q.size();
            for(int i = 0; i < curr;i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto& dir : directions){
                    int rd = dir[0] + r;
                    int cd = dir[1] + c;

                    if(rd < 0 || cd < 0 || rd == ROWS || cd == COLS || grid[rd][cd] != 1){
                        continue;
                    }
                    freshCount--;
                    grid[rd][cd] = 2; //make orange rotten
                    q.push({rd,cd}); //push new rotten orange to next layer
                }
            }
            minutes++;
        }

        return freshCount == 0 ? minutes-1 : -1;
    }
};