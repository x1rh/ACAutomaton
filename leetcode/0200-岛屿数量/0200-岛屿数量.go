func numIslands(grid [][]byte) int {
    m := len(grid)
    n := len(grid[0])

    var dfs func(i, j int) 

    var dir  = []struct{x, y int}{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

    dfs = func(i, j int) {
        for k := range dir {
            x := i + dir[k].x
            y := j + dir[k].y 

            if 0<=x&&x<m && 0<=y&&y<n && grid[x][y] == '1' {
                grid[x][y] = '0'
                dfs(x, y)
            }
        }
    }

    ans := 0 
    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {
            if grid[i][j] == '1' {
                ans += 1
                dfs(i, j)
            }
        }
    }
    return ans 
}