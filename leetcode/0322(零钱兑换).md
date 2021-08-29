# 题目
`https://leetcode-cn.com/problems/coin-change/`


# 思路
设dp[i]表示金额为i所需要的最少硬币  
初始化为dp[0]=0，表示0需要0个硬币组成  
转移方程： dp[i] = min(dp[i-coins[j]]+1, dp[i])  

注意这个`1` 十分精髓，不要考虑一次性拿多个coins[j]，而是拿一个coins[j]，从i-coins[j]的位置转移过来



```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i=1; i<=amount; ++i){
            for(int j=0; j<coins.size(); ++j){
                if(i>=coins[j]){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]==0x3f3f3f3f?-1:dp[amount];
    }
};
```