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