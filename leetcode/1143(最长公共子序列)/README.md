# 题目
`https://leetcode-cn.com/problems/longest-common-subsequence/`

# 思路
记dp[i][j]表示长度为i的text1和长度长度为j的text2的最长公共子序列的长度。
初始化为`dp[0][j]=0 和 dp[i][0]=0`  
转移方程：
- `dp[i][j] = dp[i-1][j-1]  if text1[i-1]==text2[j-1]`
- `dp[i][j] = max(dp[i-1][j], dp[i][j-1])  if text1[i-1] != text2[j-1]`


```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }
        return dp[m][n];
    }
};
```
