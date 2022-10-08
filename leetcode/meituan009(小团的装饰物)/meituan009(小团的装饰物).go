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