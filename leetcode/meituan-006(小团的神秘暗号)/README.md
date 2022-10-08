# 题目
[meituan-006. 小团的神秘暗号](https://leetcode-cn.com/problems/z3XKBp/)


# 题意
给你一个已经加密的字符串，组成为header + content + tail，并给出header和tail的定义
，求content


# 思路
按定义模拟即可

```go
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

```

