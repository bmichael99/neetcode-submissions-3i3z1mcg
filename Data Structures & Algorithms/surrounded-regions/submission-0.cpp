class Solution {
public:
    int ROWS;
    int COLS;
    void solve(vector<vector<char>>& board) {
        //go around the edges of the board and mark all areas connected to O's here as unreachable. Then turn all O's that aren't reachable from the edge of the board into X's
        ROWS = board.size();
        COLS = board[0].size();
        vector<vector<bool>> reachable(ROWS, vector<bool>(COLS, false));


        //left and right borders
        for(int i = 0; i < ROWS; i++){
            if(board[i][0] == 'O' && !reachable[i][0]){
                DFS(i,0,board,reachable);
            }
            if(board[i][COLS-1] == 'O' && !reachable[i][COLS-1]){
                DFS(i,COLS-1,board,reachable);
            }
        }

        //top and bottom borders
        for(int i = 0; i < COLS; i++){
            if(board[0][i] == 'O' && !reachable[0][i]){
                DFS(0,i,board,reachable);
            }
            if(board[ROWS-1][i] == 'O' && !reachable[ROWS-1][i]){
                DFS(ROWS-1,i,board,reachable);
            }
        }

        //turn all O's that aren't reachable from O's connected to edges into X's
        for(int r = 1; r < ROWS-1;r++){
            for(int c = 1; c < COLS-1;c++){
                if(!reachable[r][c] && board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }

    }

    void DFS(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& reachable){
        if(r < 0 || c < 0 || r == ROWS || c == COLS || reachable[r][c] || board[r][c] == 'X'){
            return;
        }

        reachable[r][c] = true;

        DFS(r+1,c,board,reachable);
        DFS(r-1,c,board,reachable);
        DFS(r,c+1,board,reachable);
        DFS(r,c-1,board,reachable);

    }
};