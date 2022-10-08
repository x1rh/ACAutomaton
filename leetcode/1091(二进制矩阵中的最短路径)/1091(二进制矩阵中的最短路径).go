type node struct{
    x, y, c int
}

func shortestPathBinaryMatrix(grid [][]int) int {
    if grid[0][0] == 1 {
        return -1 
    }

    d := []struct{x, y int}{{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}}
    m := len(grid)
    n := len(grid[0])

    q := []node{}
    vis := make([][]bool, m)
    for i:=0; i<m; i++ {
        vis[i] = make([]bool, n)
    }
    
    q = append(q, node{0, 0, 0})
    vis[0][0] = true 

    for len(q) > 0 {
        fr := q[0]
        if fr.x == m-1 && fr.y==n-1 {
            return fr.c + 1
        }
        q = q[1:len(q)]

        for i := range d {
            x := d[i].x + fr.x 
            y := d[i].y + fr.y 
            if 0<=x&&x<m && 0<=y&&y<n && !vis[x][y] && grid[x][y]==0{
                vis[x][y] = true 
                q = append(q, node{x, y, fr.c+1})
            }
        }
    }
    return -1 
}