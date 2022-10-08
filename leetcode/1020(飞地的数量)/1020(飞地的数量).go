func numEnclaves(grid [][]int) int {
    d := []struct{x, y int}{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
    m := len(grid)
    n := len(grid[0])

    var dfs func(i, j int) 

    dfs = func(i, j int) {
        for k := range d {
            x := d[k].x + i 
            y := d[k].y + j
            if 0<=x&&x<m && 0<=y&&y<n && grid[x][y] == 1 {
                grid[x][y] = 0 
                dfs(x, y)
            }
        }
    }

    for i:=-1; i<=m; i++ {
        dfs(i, -1)
        dfs(i, n)
    }

    for i:=-1; i<=n; i++ {
        dfs(-1, i)
        dfs(m, i)
    }

    ans := 0 
    for i := range grid {
        for j := range grid[i] {
            if grid[i][j] == 1 {
                ans += 1 
            }
        }
    }

    return ans 
}