class Solution {
public:
    bool g;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    void dfs(string& w, int idx, int x, int y, int turn, 
        vector<vector<pair<int, int>>>& sc, 
        vector<vector<int>>& vis,
        vector<vector<char>>& board
    ){
        if(g) return;
        if(idx == w.size()){
            g = true;
            return;
        }
        for(int i=0; i<4; ++i){
            int cx = dx[i] + x;
            int cy = dy[i] + y;
            if(0<=cx&&cx<board.size() && 0<=cy&&cy<board[0].size()){
                if(board[cx][cy]==w[idx] && vis[cx][cy]!=turn){
                    vis[cx][cy] = turn;
                    dfs(w, idx+1, cx, cy, turn, sc, vis, board);
                    vis[cx][cy] = turn - 1;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int, int>>> sc(26, vector<pair<int, int>>());
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                sc[board[i][j] - 'a'].emplace_back(i, j);
            }
        }


        vector<string> ans;
        for(int i=0; i<words.size(); ++i){
            if(words[i].size() > m*n) continue;

            for(int j=0; j<sc[ words[i][0] - 'a' ].size(); ++j){
                auto [x, y] = sc[ words[i][0] - 'a' ][j];
                g = false;
                vis[x][y] = i+1;
                dfs(words[i], 1, x, y, i+1, sc, vis, board);
                vis[x][y] = i;
                if(g){
                    ans.emplace_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};