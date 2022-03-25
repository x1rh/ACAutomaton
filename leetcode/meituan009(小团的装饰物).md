# 题目
[meituan-009. 小团的装饰物](https://leetcode-cn.com/problems/0VvYxa/)

# 题意
长度为m的数组，要求i中的数是i-1中的数的倍数，且数组最后一个数小于等于n。问有多少种组合

# 思路

定义`dp[i][j]`表示长度为i，第i个物品的价格为j时有几种方案。 （1-index）

那么答案为：`sum(dp[m][j]) 1<=j<=n`

时间复杂度`O(m*n* sqrt(n))`


```go
package main 

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    var m, n int 

    r := bufio.NewReader(os.Stdin)
    fmt.Fscan(r, &n, &m)

    dp := make([][]int, m+1)

    
    for i:=0; i<=m; i++ {
        dp[i] = make([]int, n+1)
        for j:=1; j<=n; j++ {
            if i == 0 {
                continue 
            }

            if i == 1 {
                dp[i][j] = 1 
                continue 
            }
            for k:=1; k*k<=j; k++ {
                if j%k==0 {
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % 998244353 
                    if k*k != j {
                        dp[i][j] = (dp[i][j] + dp[i-1][j/k]) % 998244353 
                    }
                    
                }
            }           
        }

    }

    ans := 0 
    for i:=1; i<=n; i++ {
        ans = (ans + dp[m][i]) % 998244353
    }
    fmt.Printf("%v", ans)   
}
```