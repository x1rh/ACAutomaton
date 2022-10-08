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