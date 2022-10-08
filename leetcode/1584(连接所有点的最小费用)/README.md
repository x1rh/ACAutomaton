# 题目
[1584. 连接所有点的最小费用](https://leetcode-cn.com/problems/min-cost-to-connect-all-points/)

# 题意
最小生成树裸题

# 思路
```go
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
```

# 小封装一下
```go
type pair struct {
    to, d int 
}

type G struct {
    g [][]pair 
    n int 
}

func (g *G) prim(start int) int{
    inf := 0x3f3f3f3f 
    dist := make([]int, g.n)
    for i:=0; i<g.n; i++ {
        dist[i] = inf 
    }
    vis := make([]bool, g.n)
    dist[start] = 0 
    res := 0

    for i:=0; i<g.n; i++ {
        to := -1 
        min := inf 
        for j:=0; j<g.n; j++ {
            if !vis[j] && dist[j] < min {
                to = j
                min = dist[j] 
            }        
        }

        res += min 
        vis[to] = true 
        for j:=0; j<len(g.g[to]); j++ {
            u := g.g[to][j].to
            d := g.g[to][j].d 
            if !vis[u] && dist[u] > d {
                dist[u] = d 
            } 
        }
    }
    return res
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
    g := &G{g: make([][]pair, n), n: n}

    for i:=0; i<g.n; i++ {
        for j:=i+1; j<n; j++ {
            d := dist(points[i][0], points[i][1], points[j][0], points[j][1])
            g.g[i] = append(g.g[i], pair{j, d})
            g.g[j] = append(g.g[j], pair{i, d})
        }
    }

    return g.prim(0) 
}
```