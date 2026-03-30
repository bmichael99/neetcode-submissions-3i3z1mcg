class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }
        //to fill each empty room with the distance to its nearest gate, we start from gates and replace INF with the current distance from that gate. We stay within the empty room meaning 1. we don't go past other gates and 2. don't go past obstacles. We want to start from every gate once but we also need to keep in the mind the nearest gates since rooms can have more than 1 gate, so we continue through a room if distance from the current gate is less than the distance marked in the grid, this also lets us continue if the room is INF, so it covers both cases of us being at a closer gate or an unexplored room.

        int ROWS = rooms.size();
        int COLS = rooms[0].size();
        queue<pair<int,int>> q;

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(rooms[r][c] == 0){//find gates and explore from them
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
            //go through current layer of the q
            int curr = q.size();
                auto [r,c] = q.front();
                q.pop();

            vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
            for(vector<int>& dir: directions){
                int rd = dir[0] + r;
                int cd = dir[1] + c;

                if(rd < 0 || cd < 0 || rd == ROWS || cd == COLS || rooms[r][c]+1 >= rooms[rd][cd]){
                    continue;
                }
                rooms[rd][cd] = rooms[r][c]+1;
                q.push({rd,cd});
            }
            
        }
    }
};