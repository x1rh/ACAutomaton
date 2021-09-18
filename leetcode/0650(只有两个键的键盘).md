# 题目
`https://leetcode-cn.com/problems/2-keys-keyboard/`

# 题意
初始时，字符串为`A`（即1个`A`），有两种操作：
1. 复制整个当前字符串
2. 粘贴所复制的内容

求构造n个`A`的字符串最少需要几步。  


# 思路
设f(n)表示第n次复制时，字符串的长度，则:
f(n) = x1 * f(n-1)
     = x1 * x2 * f(n-2)
     = x1 * x2 * .... * f(1)

f(1) = 1

min(x1+x2+x3+...) 则是我们所求的答案。

利用以上结论，不难设计出带记忆（用于剪枝）的dfs，暴力每一个可能的xi



```cpp
class Solution {
public:
    void dfs(int cp, int cost, int n, map<int, int>& mp){
        for(int i=2*cp; i<=n; i+=cp){
            if(n%i==0){
                int cn = cost+i/cp;
                auto it = mp.find(i);
                if(it != mp.end()){ 
                    if(cn < mp[i]){
                        mp[i] = cn;
                        dfs(i, cn, n, mp);
                    }
                }
                else{
                    mp[i] = cn;
                    dfs(i, cn, n, mp);
                }
            }
        }
    }


    int minSteps(int n) {
        map<int, int> mp;
        dfs(1, 0, n, mp);
        return mp[n];
    }
};
```


# 解法2：dp
设dp[i]表示i个A需要的最少操作。
基于上面dfs解法中的结论，枚举每个`j`, `j`满足`j<i`且j是i的因数，复制`i/j-1`次`j个A`即可得到`i个A`，花费为`i/j`(1次复制，i/j-1次粘贴), 转移方程为`dp[i] = min(dp[i], dp[j]+i/j);`


```cpp
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for(int i=2; i<=n; ++i){
            dp[i] = INT_MAX;
            for(int j=1; j<i; ++j){
                if(i%j==0){
                    dp[i] = min(dp[i], dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};
```