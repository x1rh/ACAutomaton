# 题目
[740. 删除并获得点数](https://leetcode-cn.com/problems/delete-and-earn/)

# 题意
取nums[i]，则不能取nums[i-1]和nums[i+1],求最大点数


# 思路
- 先将数据处理到桶中
- 定义dp[i] 表示，取到位置i时的最大得分
- 状态转移方程： `dp[i] = max(dp[i-1], dp[i-2]+cnt[i]*i)`， 和[leetcode198](https://leetcode-cn.com/problems/house-robber/)一模一样
- 设abc连续，起始取b便不能取ac，蕴含在取b就不能取a中，所以和leetcode198一样

```go
func deleteAndEarn(nums []int) int {
    cnt := make([]int, 10002)
    for i:=0; i<len(nums); i++ {
        cnt[nums[i]] += 1 
    }

    n := 10000
    dp := make([]int, n+1)
    for i:=1; i<=n; i++ {
        if i>=3 {
            dp[i] = max(dp[i-1], dp[i-2]+cnt[i]*i)
        } else if i>=2 {
            dp[i] = max(dp[i-1], cnt[i]*i)
        } else {
            dp[i] = cnt[i] * i 
        }
    }
    return dp[n]
}

func max(x ,y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
}
```