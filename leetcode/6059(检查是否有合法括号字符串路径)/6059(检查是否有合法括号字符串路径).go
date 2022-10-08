func hasValidPath(grid [][]byte) bool {
    m := len(grid)
    n := len(grid[0])
    
    vis := make([][][]bool, m)
    for i:=0; i<m; i++ {
        vis[i] = make([][]bool, n)
        for j:=0; j<n; j++ {
            vis[i][j] = make([]bool, m+n)
        }
    }

    flag := false 
    var dfs func(int, int, int) 
    dfs = func(i, j, c int) {
        if grid[i][j]  == '(' {
            c += 1 
        } else {
            c -= 1 
        }
        if c < 0 {
            return 
        }
        if vis[i][j][c] {
            return 
        }
        vis[i][j][c] = true 
        
        if i==m-1 && j==n-1 {
            if c == 0{
                flag = true 
            }
        }
        if flag {
            return 
        }
        
        if i+1 < m {
            dfs(i+1, j, c)
        }
        if j+1 <n {
            dfs(i, j+1, c)
        }
    }
    dfs(0, 0, 0)
    return flag 
}
