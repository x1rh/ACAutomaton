# 题目
[1230. 抛掷硬币](https://leetcode.cn/problems/toss-strange-coins/)

# 题意
给出n个硬币正面向上的概率，现在抛掷每个硬币一次，求刚好target个硬币正面向上的概率。

# 思路
考虑dfs，那么需要凑出大小为target的所有可能的方案，并累加概率，参考题目数据范围肯定TLE

dp，设dp[i][j]表示前i个硬币刚好有j个正面朝上的，那么转移方程:
- `dp[i][j] = dp[i-1][j] * (1 - prob[i]) + dp[i-1][j-1] * prob[i]    j != 0`
- `dp[i][j] = dp[i-1][j] * (1 - prob[i])                             j == 0`

初始化：`dp[0][0]=1` 表示 0个硬币构成刚好0个正面朝上的概率为1 


```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> f(n+1, vector<double>(target+1, 0));
        f[0][0] = 1.0;

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=i && j <=target; j++) {
                if(j >= 1) {
                    f[i][j] = f[i-1][j] * (1 - prob[i-1]) + f[i-1][j-1] * prob[i-1];
                } else {
                    f[i][j] = f[i-1][j] * (1 - prob[i-1]);
                }
            }
        }
        return f[n][target];
    }
};
```


优化空间, 二维降一维：
```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> f(target + 1);
        f[0] = 1.0;

        for(int i=1; i<=n; i++) {
            for(int j=min(target, i); j>=1; j--) {
                f[j] = f[j] * (1 - prob[i-1]) + f[j-1] * prob[i-1];
            }
            f[0] *= 1 - prob[i-1];
        }
        return f[target];
    }
};
```
注意，因为要同时用到f[j]和f[j-1]，如果从0到target进行遍历，那么f[j-1]将会被覆盖，但是如果从target到0遍历，那么都不会在使用前被覆盖 
