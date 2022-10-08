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