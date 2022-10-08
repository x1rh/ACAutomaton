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