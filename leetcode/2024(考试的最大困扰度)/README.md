# 题目
[2024. 考试的最大困扰度](https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam/)

# 题意
最多改变k次，求最长的T串或F串


# 思路
滑动窗口

```go
func maxConsecutiveAnswers(s string, k int) int {
    n := len(s)

    var i, j int 

    cal := func(x byte) int { 
        cnt := 0 
        res := 0 
        for i,j=0,0; j<n; j++{
            if s[j] == x {
                if cnt < k {
                    cnt += 1 
                } else {
                    for ; i<=j; i++ {
                        if s[i] == x {
                            i += 1 
                            break 
                        }
                    }
                }
            } 

            if j-i+1 > res {
                res = j-i+1 
            }
        }
        return res 
    }

    max := func(x, y int) int {
        if x > y {
            return x 
        } else {
            return y 
        }
    }


    return max(cal('T'), cal('F'))
}
```