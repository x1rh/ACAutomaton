func minStickers(stickers []string, target string) int {
    m := len(stickers)
    n := len(target)
    cnt := make([][]int, m)
    for i := 0; i < m; i++ {
        cnt[i] = make([]int, 26)
        for j := 0; j < len(stickers[i]); j++ {
            cnt[i][stickers[i][j] - 'a'] += 1 
        }
    }

    maxn := 1<<n; 
    inf := 0x3f3f3f3f 
    f := make([]int, maxn)
    for i:=0; i<maxn; i++ {
        f[i] = inf 
    }
    f[0] = 0  
    for i := 0; i < maxn; i++ {
        if f[i] != inf {
            for j := 0; j < m; j++ {
                next := i 
                c := make([]int, 26)
                copy(c, cnt[j])
                for k := 0; k < n; k++ {
                    if (i>>k) & 1 == 0 && c[target[k]-'a'] > 0 {
                        c[target[k]-'a'] -= 1 
                        next ^= 1<<k                    
                    }
                }
                if f[next] > f[i] + 1 {
                    f[next] = f[i] + 1 
                }
            }
        }
    }
    if f[maxn-1] == inf {
        return -1 
    } else {
        return f[maxn-1]
    }
}