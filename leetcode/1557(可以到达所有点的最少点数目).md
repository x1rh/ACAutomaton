# 题目
[1557. 可以到达所有点的最少点数目](https://leetcode-cn.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)


# 题意


# 思路
等价求入度为0的点

```go
func findSmallestSetOfVertices(n int, edges [][]int) []int {
    ans := []int{}
    deg := make([]int, n)

    for i := range edges {
        
        y := edges[i][1]
        deg[y] += 1 
    }

    for i:=0; i<n; i++ {
        if deg[i] == 0 {
            ans = append(ans, i)
        }
    }

    return ans 
}
```