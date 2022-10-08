package main 

import (
    "bufio"
    "fmt"
    "os"
)


func main() {
    var m, n, ans int 
    r := bufio.NewReader(os.Stdin)
    fmt.Fscan(r, &m, &n)

    arr := make([]int, n)
    for i:=0; i<n; i++ {
        fmt.Fscan(r, &arr[i])
    }


    for i:=1; i<=m; i++ {        
        var l, r int 
        for l, r = i, m; l<=r; {
            mid := (l+r)/2 

            pre := -1
            flag := false 
            
            for _, x := range arr {
                if (0<x&&x<i) || (mid<x&&x<m+1) {
                    if pre <= x {
                        pre = x 
                    } else {
                        flag = true
                        break 
                    }
                } 
            }

            if !flag {
                r = mid -1 
            } else {
                l = mid + 1
            }
        }

        ans += m-l+1
        
    }
    fmt.Printf("%v", ans)
}