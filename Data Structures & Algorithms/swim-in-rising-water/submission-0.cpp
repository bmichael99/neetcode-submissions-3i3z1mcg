class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //you can swim between squares that are at most t (<= t).
        //return minimum time to reach bottom right square if you start at the top left square

        //BFS from top left until you can reach bottom right, use a minHeap to always get possibly available squares first

        int ROWS = grid.size();
        int COLS = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS,false));

        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        minHeap.push({grid[0][0],{0,0}});
        int t = 0;
        while(!minHeap.empty()){
          if(minHeap.top().first > t){
            t++;
            continue;
          }

          auto [curr,cords] = minHeap.top();
          auto [r,c] = cords;
          minHeap.pop();
          if(r == ROWS-1 && c == COLS-1) return t; //if we found bottom right, return t
          visited[r][c] = true;

          for(vector<int>& dir : directions){
            int rd = r + dir[0];
            int cd = c + dir[1];

            if(rd < 0 || cd < 0 || rd == ROWS || cd == COLS || visited[rd][cd] == true){
              continue;
            }

            minHeap.push({grid[rd][cd],{rd,cd}});
          }

        }

        return t;
    }
};