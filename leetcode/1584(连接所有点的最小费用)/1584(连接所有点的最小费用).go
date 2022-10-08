type pair struct {
    to, d int 
}

func abs(x int) int {
    if x < 0 {
        return -x 
    } else {
        return x 
    }
}

func dist(x1, y1, x2, y2 int) int {
    return abs(x2-x1) + abs(y2-y1) 
}


func minCostConnectPoints(points [][]int) int {
    n := len(points)
    g := make([][]pair, n)
    for i:=0; i<n; i++ {
        for j:=i+1; j<n; j++ {
            d := dist(points[i][0], points[i][1], points[j][0], points[j][1])
            g[i] = append(g[i], pair{j, d})
            g[j] = append(g[j], pair{i, d})
        }
    }


    prim := func(start int) int{
        inf := 0x3f3f3f3f 
        dist := make([]int, n)
        for i:=0; i<n; i++ {
            dist[i] = inf 
        }
        vis := make([]bool, n)
        dist[start] = 0 
        res := 0
    
        for i:=0; i<n; i++ {
            to := -1 
            min := inf 
            for j:=0; j<n; j++ {
                if !vis[j] && dist[j] < min {
                    to = j
                    min = dist[j] 
                }        
            }

            res += min 
            vis[to] = true 
            for j:=0; j<len(g[to]); j++ {
                u := g[to][j].to
                d := g[to][j].d 
                if !vis[u] && dist[u] > d {
                    dist[u] = d 
                } 
            }
        }
        return res
    }
    return prim(0) 
}