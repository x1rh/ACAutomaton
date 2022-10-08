# 题目
`https://leetcode-cn.com/problems/edit-distance/`


# 思路
记`dp[i][j]`为`word1[0...i]`和`word2[0...j]`的最短编辑距离。  
- 初始化为:  
  - `dp[i][0] = i`
  - `dp[0][j] = j`
- 转移方程:
  - `dp[i][j] = min(min(min(dp[i-1][j]+1, dp[i][j-1]+1), word1[i-1]==word2[j-1]?dp[i-1][j-1]:dp[i-1][j-1]+1), dp[i][j])`



```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==0 || n==0) return m+n;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0x3f3f3f3f));
        for(int i=0; i<=m; ++i) dp[i][0] = i;
        for(int i=0; i<=n; ++i) dp[0][i] = i;
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1, dp[i][j-1]+1));
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
```