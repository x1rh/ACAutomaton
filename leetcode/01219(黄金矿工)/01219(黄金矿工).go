func getMaximumGold(grid [][]int) int {
    var dx = []int{0, 0, -1, 1}
    var dy = []int{-1, 1, 0, 0}

    ans := 0
    m := len(grid)
    n := len(grid[0])

    var dfs func(g [][]int, i, j, t int)
    dfs = func(g [][]int, i, j, t int){
        t += g[i][j];
        g[i][j] = 0;
        if ans < t {
            ans = t
        }
        for ii:=0; ii<4; ii++{
            x := dx[ii] + i;
            y := dy[ii] + j;
            if(0<=x&&x<m && 0<=y&&y<n && g[x][y]!=0){
                dfs(g, x, y, t);
            }
        }
        g[i][j] = grid[i][j];
    }

    g := make([][]int, m)
    for k:=0; k<m; k++ {
        g[k] = make([]int, n)
    }
    

    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {
            if grid[i][j] != 0 {

                for k:=0; k<m; k++ {
                    copy(g[k], grid[k]);
                }
                dfs(g, i, j, 0)
            }
        }
    }

    return ans;
}