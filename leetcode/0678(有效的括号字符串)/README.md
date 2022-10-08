# 题目
`https://leetcode-cn.com/problems/valid-parenthesis-string/submissions/`

# 思路
记dp[i][j]表示s前i个字符串后拼接j个`)`是否能组成一个合法的字符串：
- 初始化：dp[0][0] 表示空串是一个合法的字符串
- 目标是dp[n][0]
- 转移方程:
  - 当s[i-1]='(' 时 dp[i][j] = dp[i-1][j-1]
  - 当s[i-1]=')' 时 dp[i][j] = dp[i-1][j+1]   想象把一个`)`借到后面的j个`)`中，然后再拿回来
  - 当s[i-1]='*' 时 dp[i][j] = dp[i-1][j-1] | dp[i-1][j+1] | dp[i-1][j]  dp[i-1][j]表示当前为星号时视其为空


```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=n; ++j){
                if(s[i-1]=='(' && j-1>=0){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(s[i-1]=='*'){
                    dp[i][j] = dp[i-1][j];
                    if(j-1>=0) dp[i][j] = dp[i][j] | dp[i-1][j-1];
                    if(j+1<=i) dp[i][j] = dp[i][j] | dp[i-1][j+1];
                }
                else if(s[i-1]==')' && j+1<=i){
                    dp[i][j] = dp[i-1][j+1];
                }
            }
        }
        return dp[n][0];
    }
};
```