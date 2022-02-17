## 题目
[688-骑士在棋盘上的概率](https://leetcode-cn.com/problems/knight-probability-in-chessboard/)

## 题意
给定棋盘的大小n*n， 给定马的起始位置(row, column), 马每次随机往8个方向跳跃，最多跳跃k步，求马还留在棋盘内的概率。

## 思路
- dp, 设dp[s][i][j]表示总共走s步且从(i, j)出发的马留在棋盘内的概率
- 初始化： `dp[0][i][j] = 1， 0<=i<n, 0<=j<n`，表示第0步
- 转移：dp[s][i][j] = dp[s-1][x][y]， i和j非常抽象...


cpp: 
```cpp
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
```

Go:
```go
func knightProbability(n int, k int, row int, column int) float64 {
    dx := []int{2, 2, -2, -2, 1, 1, -1, -1}
    dy := []int{1, -1, 1, -1, 2, -2, 2, -2}
    dp := make([][][]float64, k+1);
    for s:=0; s<=k; s++ {
        dp[s] = make([][]float64, n)
        for i:=0; i<n; i++ {
            dp[s][i] = make([]float64, n)
            for j:=0; j<n; j++ {
                if s==0 {
                    dp[s][i][j] = 1
                } else {
                    for h:=0; h<8; h++ {
                        x := dx[h] + i
                        y := dy[h] + j
                        if 0<=x&&x<n && 0<=y&&y<n {
                            dp[s][i][j] += dp[s-1][x][y] / 8
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column]
}
```
