class Solution {
public:
    bool check(vector<vector<char>>& board, int dx, int dy){
        vector<bool> vis(10, false);
        for(int i=dx; i<dx+3; ++i){
            for(int j=dy; j<dy+3; ++j){
                if('1'<=board[i][j] && board[i][j]<='9'){
                    if(!vis[board[i][j]-'0']){
                        vis[board[i][j]-'0'] = true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(!check(board, i*3, j*3)){
                    return false;
                }
            }
        }
        for(int i=0; i<9; ++i){
            vector<bool> vis(10, false);
            for(int j=0; j<9; ++j){
                if('1'<=board[i][j] && board[i][j]<='9'){
                    if(!vis[board[i][j]-'0']){
                        vis[board[i][j]-'0'] = true;
                    }
                    else{
                        return false;
                    }
                }    
            }
        }
        for(int i=0; i<9; ++i){
            vector<bool> vis(10, false);
            for(int j=0; j<9; ++j){
                if('1'<=board[j][i] && board[j][i]<='9'){
                    if(!vis[board[j][i]-'0']){
                        vis[board[j][i]-'0'] = true;
                    }
                    else{
                        return false;
                    }
                }    
            }
        }
        return true;
    }
};