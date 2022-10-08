# 题目
[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)


# 思路
递推

```go
func climbStairs(n int) int {
    dp := make([]int, 46)

    dp[0] = 0
    dp[1] = 1
    dp[2] = 2 

    for i:=3; i<=n; i++ {
        dp[i] = dp[i-1] + dp[i-2]
    }
    return dp[n]
}
```


```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
```