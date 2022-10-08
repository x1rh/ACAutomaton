# 题目
[meituan-001. 小美的用户名](https://leetcode-cn.com/problems/BaR9fy/)

# 思路
按题意模拟

```go
package main 

import (
    "fmt"
    "unicode"
)

func check(s string) bool {
    upper := 0 
    lower := 0 
    number := 0 
    for i, c := range s {
        if i == 0 {
            if unicode.IsLetter(c) {
                
            } else {
                return false 
            }
        } 

        if unicode.IsUpper(c) {
            upper += 1
        } else if unicode.IsLower(c) {
            lower += 1
        } else if unicode.IsDigit(c) {
            number += 1
        }
    
    }


    if upper + lower + number != len(s) {
        return false 
    } else if (upper + lower == 0) || (number == 0) {
        return false 
    } else {
        return true 
    }

}


func main() {
    T := 0 
    s := ""
    fmt.Scanln(&T)
    for kase := 0; kase < T; kase++ {
        fmt.Scanln(&s)
        if check(s) {
            fmt.Println("Accept")
        } else {
            fmt.Println("Wrong")
        }
    }
}

```