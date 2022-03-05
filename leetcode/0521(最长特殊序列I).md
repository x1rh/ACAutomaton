# 题目
[521. 最长特殊序列 Ⅰ](https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/)


# 题意
判断两个字符串其中一个是否是另一个的子序列，如果是则返回另一个字符串的长度，否则返回-1


# 思路
求最长公共子序列长度，然后做判断



```go
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
```

# 正解
只要第一个字母不同，就返回长的那个字符串的长度
