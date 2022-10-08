# 题目
[309. 最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

# 题意
买卖同一只股票，要求这次买和上次卖之间间隔至少一天，问最大收益

# 思路
dp, 考虑第i天手上有无股票，没有股票时是否处于冷静期，一共2*2=4个状态，其中“有股票处于冷静期”这个状态是无效状态，所以用3个变量记录，都表示在各自条件下在下标i之前的最大收益：
- `dp[i][0] 有股票`
- `dp[i][1] 无股票，处于冷静期`
- `dp[i][2] 无股票，不处于冷静期`

转移方程：
- `dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i])`
- `dp[i][1] = dp[i-1][0] + prices[i]`
- `dp[i][2] = max(dp[i-1][2], dp[i-1][1])`

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for(int i=1; i<n; i++) { 
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
        }
        return max(dp[n-1][1], dp[n-1][2]);
    }
};
```
