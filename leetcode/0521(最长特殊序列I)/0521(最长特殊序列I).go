func max(x, y int ) int {
    if x > y {
        return x
    } else {
        return y 
    }
}

func findLUSlength(a string, b string) int {
    m := len(a)
    n := len(b)
    dp := make([][]int, m+1)
    for i := range dp {
        dp[i] = make([]int, n+1)
    }

    for i:=1; i<=m; i++ {
        for j:=1; j<=n; j++ {
            dp[i][j] = dp[i-1][j-1]
            if a[i-1] == b[j-1] {
                dp[i][j] += 1
            } 
        }
    }

    if max(m, n) == dp[m][n] {
        return -1 
    } else {
        return max(m, n)
    }
}