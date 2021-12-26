# 题目
https://leetcode-cn.com/problems/interleaving-string/


# 题意
求字符串s1和s2的子串是否能构成s3. 要求划分后的子串，拼接成s3时保持先后顺序。


# 思路
dp，设dp[i][j]表示字符串s1的前i个字符和字符串s2的前j个字符，是否能构成字符串s3的前i+j个字符。

则转移方程为：`dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1])`
初始化为`dp[0][0]=true`, 表示空串+空串=空串


```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for(int i=0; i<=s1.size(); ++i){
            for(int j=0; j<=s2.size(); ++j){
                if(i-1>=0){
                    dp[i][j] = dp[i][j] || (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
                }
                if(j-1>=0){
                    dp[i][j] = dp[i][j] || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
```