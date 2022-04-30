## 题目
[6054. 逃离火灾](https://leetcode-cn.com/problems/escape-the-spreading-fire/)

## 题意
判断是否能从`(0,0)`逃离到`(m-1,n-1)`，以及最多能在`(0,0)`呆多久后也能跑到`(m-1,n-1)`


## 解题思路
1. 先用bfs求出每个草地最快什么时候烧到
2. 0分钟开始出发，判断是否能到达出口，如果不能返回-1
3. 二分求最多能多少分钟后跑路

坑点：人和火可以同时到达出口。

```golang
type node struct {
    x, y, c int
}

func maximumMinutes(g [][]int) int {
    
    d := []struct{x, y int}{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
    
    m := len(g)
    n := len(g[0])
    q := []node{}
    vis := make([][]int, m)
    vi2 := make([][]int, m)
    inf := 0x3f3f3f3f 

    for i:=0; i<m; i++ {
        vis[i] = make([]int, n)
        vi2[i] = make([]int, n)
        for j:=0; j<n; j++ {
            if g[i][j] == 1 {
                q = append(q, node{i, j, 0})
            }
            vis[i][j] = inf
            vi2[i][j] = inf 
        }        
    }

    for len(q) > 0 {
        fr := q[0]
        q = q[1:]

        for i:=0; i<4; i++ {
            x := d[i].x + fr.x 
            y := d[i].y + fr.y 
            c := fr.c + 1 
            if 0<=x&&x<m && 0<=y&&y<n && g[x][y] != 2 && vis[x][y] > c { 
                vis[x][y] = c 
                q = append(q, node{x, y, c})
            }
        }
    }

    bfs := func (c int) int{
        for i:=0; i<m; i++ {
            for j:=0; j<n; j++ {
                vi2[i][j] = inf 
            }
        }

        q = q[0:0]
        q = append(q, node{0, 0, c})
        for len(q) > 0 {
            fr := q[0]
            q = q[1:]

            if fr.x == m-1 && fr.y == n-1 {
                return fr.c 
            }

            for i:=0; i<4; i++ {
                x := d[i].x + fr.x 
                y := d[i].y + fr.y 
                c := fr.c + 1 
                if 0<=x&&x<m && 0<=y&&y<n && g[x][y] == 0 && vi2[x][y] > c{
                    if vis[x][y] > c {
                        vi2[x][y] = c 
                        q = append(q, node{x, y, c})
                    } else if vis[x][y] == c && x==m-1 && y==n-1 {
                        return c 
                    }
                }
            }
        }
        return -1 
    }

    ok := bfs(0)

    if ok == -1 {
        return -1 
    } else {
        if vis[0][0] == inf {
            return 1e9 
        } else {
            l := 0
            r := vis[0][0]-1
            for l<=r {
                mid := (l+r)/2
                if bfs(mid) == -1 {
                    r = mid -1 
                } else {
                    l = mid + 1 
                }
            }
            return r
        }
    }

}
```
