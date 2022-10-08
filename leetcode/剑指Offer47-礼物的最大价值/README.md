# 题目
[剑指 Offer 47. 礼物的最大价值]()

# 题意
从左上角走到右上下角，每次可以向右或向下，每个格子都有一个权值，求路径的最大权值和。

# 思路
简单dp，转移方程为`dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1])`。

```go
func maxValue(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {
            if 0<=j-1 && 0<=i-1{
                grid[i][j] += max(grid[i][j-1], grid[i-1][j])
            } else if 0<=i-1 {
                grid[i][j] += grid[i-1][j]
            } else if 0<=j-1 {
                grid[i][j] += grid[i][j-1]
            }
        }
    }
    return grid[m-1][n-1]
}

func max(x, y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
}
```