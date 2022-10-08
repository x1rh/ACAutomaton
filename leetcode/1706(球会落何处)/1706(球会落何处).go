func findBall(grid [][]int) []int {
    m := len(grid)
    n := len(grid[0])
    ans := make([]int, n)

    for j:=0; j<n; j++ {
        if j==0 && grid[0][0] == -1 {
            ans[j] = -1
            continue;
        }
        if j == n-1 && grid[0][n-1] == 1 {
            ans[j] = -1 
            continue;
        }

        backup := j
        for i:=0; i<m; i++ {
            if grid[i][j] == 1 && j+1 <n && grid[i][j+1] == 1 {
                j += 1
            } else if grid[i][j] == -1 && j-1 >=0 && grid[i][j-1] == -1{
                j -= 1
            } else {
                ans[backup] = -1
                break
            }
        }
        if ans[backup] != -1 {
            ans[backup] = j
        }     
        j = backup 
    }
    return ans 
}