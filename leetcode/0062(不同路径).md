# 题目
`https://leetcode-cn.com/problems/unique-paths/`


# 思路
很简单的dp递推
设dp[i][j]表示到达点(i, j)的路径数，则转移方程：
`dp[i][j] = dp[i-1][j] + dp[i][j-1]`  

注意初始化，我这里行和列都多增加一行，方便处理边界

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][1] = 1;
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
```

