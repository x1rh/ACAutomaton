# 题目
`https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/`


# 思路

设`dp[i][j]`表示从src经过j个站点到达i的最小花费
初始化:
- `dp[i][0] = cost`   i不等于src, 且存在从scr到i的边，长为cost 
- `dp[src][0] = 0` 

转移方程： `dp[i][j] = min(dp[i][j], dp[t][j-1]+edge(t, i))`  其中t来源于边(t, i)


```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> dp(n, vector<int>(k+1, inf));
        
        for(auto &f : flights){
            int fr = f[0];
            int to = f[1];
            int co = f[2];
            if(fr==src){
                dp[to][0] = co;
            }
        }
        dp[src][0] = 0;

        for(int i=1; i<=k; ++i){
            for(auto &f : flights){
                int fr = f[0];
                int to = f[1];
                int co = f[2];
                dp[to][i] = min(dp[fr][i-1]+co, dp[to][i]);
            }
        }

        int ans = inf;
        for(int i=0; i<=k; ++i){
            ans = min(dp[dst][i], ans);
        }
        return ans==inf?-1:ans;
    }
};
```