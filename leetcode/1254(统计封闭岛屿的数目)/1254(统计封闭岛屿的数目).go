func closedIsland(grid [][]int) int {
    d := []struct{x, y int}{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
    m := len(grid)
    n := len(grid[0])

    check := func(x, y int) bool {
        flag := 0 

        for i:=x-1; i>=0; i-- {
            if grid[i][y] == 1 {
                flag += 1
                break 
            }
        }

        for i:=x+1; i<m; i++ {
            if grid[i][y] == 1 {
                flag += 1
                break 
            }
        }

        for i:=y-1; i>=0; i-- {
            if grid[x][i] == 1 {
                flag += 1
                break 
            }
        }

        for i:=y+1; i<n; i++ {
            if grid[x][i] == 1 {
                flag += 1
                break 
            }
        }

        return flag == 4
    }

    var dfs func(i, j int) bool 

    dfs = func(i, j int) bool {
        flag := true 
        grid[i][j] = 1 
        for k := range d {
            x := d[k].x + i 
            y := d[k].y + j 

            if 0<=x&&x<m && 0<=y&&y<n && grid[x][y]==0{
                if check(x, y) {
                    if !dfs(x, y) {
                        flag = false 
                        break 
                    }
                } else {
                    flag = false
                    break  
                }
            }
        }
        if flag {
            return true 
        } else {
            grid[i][j] = 0 
            return false 
        }
    }

    ans := 0 
    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {
            if grid[i][j]==0 && check(i, j){
                if dfs(i, j) {
                    ans += 1 
                }
            } 
        }
    }
    return ans 
}