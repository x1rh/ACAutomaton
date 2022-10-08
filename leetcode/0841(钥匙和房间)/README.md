# 题目
[841. 钥匙和房间]()

# 思路

```go
func canVisitAllRooms(rooms [][]int) bool {
    n := len(rooms)
    vis := make([]bool, n)
    var dfs func(int) 

    dfs = func(i int) {
        vis[i] = true 

        for j := range rooms[i] {
            next := rooms[i][j]
            if !vis[next] {
                dfs(next)
            }
        }
    }
    dfs(0)

    for i := range vis {
        if !vis[i] {
            return false 
        }
    }

    return true 
}
```