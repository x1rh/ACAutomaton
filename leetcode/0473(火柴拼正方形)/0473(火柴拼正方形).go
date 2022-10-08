func makesquare(matchsticks []int) bool {
    n := len(matchsticks)
    sum := 0
    for i:=0; i<n; i++ {
        sum += matchsticks[i]
    }
    if sum % 4 != 0 {
        return false 
    }

    x := sum / 4
    for i:=0; i<n; i++ {
        if matchsticks[i] > x {
            return false 
        }
    }

    ans := false    
    g := []int{0, 0, 0, 0}
    var dfs func(int) 
    dfs = func(i int) {
        if ans {
            return 
        }
        if i == n {
            for j:=0; j<4; j++ {
                if g[j] != x {
                    return 
                }
            }
            ans = true 
            return 
        }
        for j:=0; j<4; j++ {
            g[j] += matchsticks[i]
            if g[j] <= x {
                dfs(i+1)
            }
            g[j] -= matchsticks[i] 
        }
    }
    dfs(0)
    return ans 
}