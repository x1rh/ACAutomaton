package main 

import (
    "fmt"
)

func main () {
    var n int 
    var s string 

    fmt.Scanln(&n)
    fmt.Scanln(&s)

    st := 0 
    ed := 0 

    for i:=0; i<len(s); i++ {
        if s[i] == 'M' {
            for j:=i+1; j<len(s); j++ {
                if s[j] == 'T' {
                    st = j + 1
                    break 
                }
            }
            break 
        }
    }

    for i:=len(s)-1; i>=0; i-- {
        if s[i] == 'T'{
            for j:=i-1; j>=0; j-- {
                if s[j] == 'M' {
                    ed = j - 1
                    break 
                }
            }
            break 
        }
    }

    if st <= ed && 0<=st && ed < len(s) {
        ans := ""
        for i:=st; i<=ed; i++ {
            ans = ans + string(s[i])
        }
        fmt.Println(ans)  
    } 
}
