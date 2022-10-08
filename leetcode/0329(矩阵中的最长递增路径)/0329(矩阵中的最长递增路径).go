type node struct {
    x, y, c  int 
}

func longestIncreasingPath(matrix [][]int) int {
    m := len(matrix)
    n := len(matrix[0])
    d := []struct{x,y int}{{-1,0}, {1,0}, {0,-1}, {0,1}}
    v := make([]node, m*n)
    vis := make([][]int, m)

    idx := 0 
    for i := range matrix {
        vis[i] = make([]int, n)
        for j:= range matrix[i] {
            v[idx].x = i 
            v[idx].y = j 
            v[idx].c = matrix[i][j]  
            idx++ 
        }
    }

    sort.Slice(v, func(i, j int)bool {
        return v[i].c < v[j].c 
    })

    q := make([]node, m*n)
    for i := range v {
        q[i].x = v[i].x
        q[i].y = v[i].y
        q[i].c = 1
    }

    ans := 1 
    for len(q) > 0 {
        fr := q[0]
        q = q[1:len(q)]

        if fr.c > ans {
            ans = fr.c 
        }

        for i := range d {
            x := fr.x + d[i].x 
            y := fr.y + d[i].y 
            c := fr.c + 1 

            if 0<=x&&x<m && 0<=y&&y<n && matrix[x][y] > matrix[fr.x][fr.y] && vis[x][y]<c{
                vis[x][y] = c 
                q = append(q, node{x,y,c})
            }
        }
    }
    return ans 
}
