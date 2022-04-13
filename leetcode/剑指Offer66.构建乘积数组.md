# 题目
[剑指 Offer 66. 构建乘积数组](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/)




# 思路
```go
func constructArr(a []int) []int {
    n := len(a)
    pre := make([]int, n+1)
    suf := make([]int, n+1)
    ans := make([]int, n)

    pre[0] = 1 
    for i:=0; i<n; i++ {
        pre[i+1] = pre[i]*a[i]
    }

    suf[n] = 1 
    for i:=n-1; i>=0; i-- {
        suf[i] = suf[i+1]*a[i] 
        ans[i] = pre[i] * suf[i+1] 
    }

    return ans 
}
```
