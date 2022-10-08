func constructDistancedSequence(n int) []int {
	m := 2*n-1
	a := make([]int, m)
	vis := make([]bool, n+1)
	var dfs func(int) bool

	dfs = func(idx int) bool {
	
		if idx == m {
			for i:=1; i<=n; i++ {
				if !vis[i] {
					return false
				}
			}
			return true
		}
		if a[idx] != 0 {
			return dfs(idx+1)
		}
		for i:=n; i>=1; i-- {
			if !vis[i] {
				if i == 1 {
					vis[i] = true
					a[idx] = i
					r := dfs(idx+1)
					if r {
						return true
					} else {
						vis[i] = false
						a[idx] = 0
					}
				} else {
					if idx+i >= m || a[idx+i] != 0 {
						continue
					}
					vis[i] = true
					a[idx] = i
					a[idx+i] = i
					r := dfs(idx+1)
					if r {
						return true
					} else {
						vis[i] = false
						a[idx] = 0
						a[idx+i] = 0
					}
				}
			}
		}
		return false
	}

	dfs(0)

	return a
}