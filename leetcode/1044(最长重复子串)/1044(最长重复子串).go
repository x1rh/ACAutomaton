const (
    p int = 31
)

func longestDupSubstring(s string) string {
    n := len(s)
    l := 1
    r := n

    pre := make([]int, n+1)
    pow := make([]int, n+1)
    pre[0] = 0 
    pow[0] = 1 
    for i:=1; i<=n; i++ {
        pre[i] = pre[i-1] * p + int(s[i-1] - 'a')
        pow[i] = pow[i-1] * p
    }

    end := -1
    for l <=r {
        mid := (l + r) / 2

        ok := false 
        vis := make(map[int]struct{})
         
        x := pre[mid]
        vis[x] = struct{}{}
        for i:=mid; i<n; i++ {
            x = x * p - int(s[i-mid] - 'a') * pow[mid] + int(s[i] - 'a')

            _, ok = vis[x]; if ok {
                end = i + 1
                break 
            } else {
                vis[x] = struct{}{}
            }
        }

        if ok {
            l = mid + 1 
        } else {
            r = mid - 1 
        }
    }
    if end == -1 {
        return "" 
    } else {
        return s[end-r:end]
    }
}