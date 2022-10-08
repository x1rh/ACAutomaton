func maxAreaOfIsland(grid [][]int) int {
    d := []struct{x, y int}{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
    m := len(grid)
    n := len(grid[0])

    var dfs func(int, int) int 

    dfs = func(i, j int) int{
        cnt := 1
        grid[i][j] = 0  

        for k := range d {
            x := d[k].x + i
            y := d[k].y + j

            if 0<=x&&x<m && 0<=y&&y<n && grid[x][y]==1{
                cnt += dfs(x, y)
            }
        }
        return cnt 
    }

    ans := 0 
    for i := range grid {
        for j := range grid[i] {
            if grid[i][j] == 1 {
                cur := dfs(i, j)
                if cur > ans {
                    ans = cur 
                }
            }
        }
    }

    return ans 
}