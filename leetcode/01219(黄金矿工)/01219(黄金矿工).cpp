class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        int ans = 0;
        function<void(vector<vector<int>>& g, int i, int j, int t)> dfs = [&](vector<vector<int>>& g, int i, int j, int t){
            t += g[i][j];
            g[i][j] = 0;
            for(int ii=0; ii<4; ++ii){
                int x = dx[ii] + i;
                int y = dy[ii] + j;
                if(0<=x&&x<m && 0<=y&&y<n && g[x][y]!=0){
                    dfs(g, x, y, t);
                }
            }
            ans = max(ans, t);
            g[i][j] = grid[i][j];
        };

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] != 0){
                    auto g = grid;
                    dfs(g, i, j, 0);
                }
            }
        }
        return ans;
    }
};