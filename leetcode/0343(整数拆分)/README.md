# 题目
`https://leetcode-cn.com/problems/integer-break/`


# 思路
求和为n的若干个正整数的最大乘积  

记dp[i]表示i拆分后的最大乘积，则dp[i] = max(dp[i], max(dp[j]*(i-j), j*(i-j)))


```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; ++i){
            int tmp = 0;
            for(int j=1; j<i; ++j){
                tmp = max(tmp, max(dp[j]*(i-j), j*(i-j)));
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};
```