# 题目
[1718. 构建字典序最大的可行序列](https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence/)

# 题意
构造一个序列，这个序列中1出现一次，2到n的每个数都出现两次，对于i属于[2, n], 使得两个值为i的数之间的距离也为i

# 思路
回溯，但是要按位置进行dfs，而不是按照数进行dfs。    
为什么我刚好用数的大小进行dfs？这题还是给了点启发价值。  

```go
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
```
