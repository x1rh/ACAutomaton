# 题目
`https://leetcode-cn.com/problems/longest-palindromic-subsequence/`

# 题意
求字符串子序列中最长的回文串

# 解法1：dp
令`dp[i][j]`表示从i到j的字符串中最长的回文串的长度。利用递推规则：
如果`s[i]==s[j] 则dp[i][j] = dp[i+1][j-1] + 2;`  
如果`s[i]!=s[j] 则dp[i][j] = max(dp[i+1][j], dp[i][j-1]);`  

此外，老生常谈的问题，dp构造顺序，需要保证`dp[i+1][j-1]`， `dp[i+1][j]`, `dp[i][j-1]`先于`dp[i][j]`进行构造

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; ++i){
            dp[i][i] = 1;
            for(int j=i-1; j>=0; --j){
                if(s[i]==s[j]){
                    dp[j][i] = dp[j+1][i-1] + 2;
                }
                else{
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
```