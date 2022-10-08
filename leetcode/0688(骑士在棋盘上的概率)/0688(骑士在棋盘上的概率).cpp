class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int dx[] = {-2, -1, 1,  2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1,  1,  2, 2, 1};

        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, 0.0)));
        
        for(int s=0; s<=k; ++s){
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(s==0){
                        dp[s][i][j] = 1.0;
                    } else {
                        for(int h=0; h<8; ++h){
                            int x = i + dx[h];
                            int y = j + dy[h];
                            if(0<=x&&x<n && 0<=y&&y<n) {
                                dp[s][i][j] += dp[s-1][x][y] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};