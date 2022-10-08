class Solution {
private:
    int m, n;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
public:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& vis, int x, int y, int pos){
        // cout<<x<<" "<<y<<" "<<pos<<endl;
        if(pos == word.size()) return false;
        if(board[x][y] != word[pos]) return false;
        if(pos == word.size()-1) return true;

        for(int i=0; i<4; ++i){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(0<=cx&&cx<m && 0<=cy&&cy<n && !vis[cx][cy]){
                vis[cx][cy] = true;
                if(dfs(board, word, vis, cx, cy, pos+1)) return true;
                vis[cx][cy] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                vis[i][j] = true;
                if(dfs(board, word, vis, i, j, 0))
                    return true;
                
            }
        }
        return false;
    }
};