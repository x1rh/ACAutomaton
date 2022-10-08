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