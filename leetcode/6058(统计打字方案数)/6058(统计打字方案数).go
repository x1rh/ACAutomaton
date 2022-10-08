func countTexts(press string) int {
    n := len(press)
    mod := int(1e9+7)
    
    cal := func(n, k int) int {
        f := make([]int, n+1)
        f[0] = 1 
        for i:=1; i<=n; i++ {
            for j:=1; j<=k; j++ {
                if i-j >= 0 {
                    f[i] = (f[i] + f[i-j]) % mod 
                }
            }
        }
        return f[n]
    }
    
    ans := 0
    t := 0
    for i,j:=0,0; i<n; i=j{
        for j=i; j<n&&press[i]==press[j]; j++ {}
        if press[i] == '7' || press[i] == '9' {
            t = cal(j-i, 4)
        } else {
            t = cal(j-i, 3)
        }     
        if ans == 0 {
            ans = t 
        } else {
            ans = (ans*t) % mod  
        }
    }
    return ans 
}
