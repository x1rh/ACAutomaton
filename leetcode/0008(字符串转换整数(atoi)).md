# 题目
[8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)

# 题意
实现atoi()

# 思路
模拟。
Go的int是int64 （64位机器），所以。。。

```go
func myAtoi(s string) int {

    pn := 0
    preNumber := false 
    
    max := int((1<<31) - 1 )
    min := -max-1 
    ans := int(0) 
    
    for _, c := range s {
        if preNumber && !unicode.IsDigit(c) {
            break 
        }

        if unicode.IsSpace(c) {
            if pn != 0 {
                break 
            } else {
                continue 
            }
        } else if c == '+' {
            if pn != 0 {
                break 
            }
            pn = 1
        } else if c == '-' {
            if pn != 0 {
                break 
            }
            pn = -1 
        } else if unicode.IsDigit(c) {
            preNumber = true 

            d := int(c-'0')
            
            
            if pn >= 0 {
                ans = ans * 10 + d
                if ans >= max {
                    ans = max 
                    break 
                }
                
            }  else { 
                ans = ans * 10 + d
                if -ans <= min {
                    ans  = min 
                    pn = 0 
                    break 
                }
            } 
        } else {
            break 
        }
    }

    if pn >= 0 {
        return ans 
    } else {
        return -ans 
    }
}

```


提供测试样例：
```go
"   42   "
"   004020 "
" -00002"
"-0.1"
"-0.6"
"   - 0.1"
"   - 110. 1111 "
"   - 110  1. 1111"
" + 110 "
" - 110 "
" +110 111"
" -110 111"
" +110 wisf"
" -100 sfaf"
" -fsdfasdf 12030"
" + fasdfsadf +123123"
"2147483648"
"2147483647"
"-2147483648"
"-2147483647"
"words and 987"
"-91283472332"
"2147483646"
"2147483639"
"21474836460"
"-21474836460"
"-2147483649"
```