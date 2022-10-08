# 题目
[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

# 题意
不能连续偷两个房子，求最大偷窃金额

# 思路
`dp[i]`表示取到第i家时的最大金额，则转移方程`dp[i] = max(dp[i-2]+nums[i], dp[i-1])`，注意一下边界即可。

```go
func rob(nums []int) int {
    n := len(nums)
    dp := make([]int, n)

    for i:=0; i<n; i++ {
        if i-2 >= 0 {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        } else if i-1>=0 {
            dp[i] = max(nums[i], dp[i-1])
        } else {
            dp[i] = nums[i] 
        }
    }

    return dp[n-1]
}

func max(x, y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
}
```
