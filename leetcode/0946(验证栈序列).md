# 题目
[946. 验证栈序列](https://leetcode-cn.com/problems/validate-stack-sequences/)

# 题意
给一个入栈序列，判断一个出栈序列是否合法。

# 思路
因为元素唯一，那么我们在入栈时，只要遇到出栈序列中的元素对应模拟即可。

```go
func validateStackSequences(pushed []int, popped []int) bool {
    s := []int{}


    for i := range pushed {
        s = append(s, pushed[i])

        for len(s)!=0 && (popped[0] == s[len(s)-1]) {
            popped = popped[1:]
            s = s[:len(s)-1]
        }
    }

    if len(popped) == 0 && len(s) == 0{
        return true 
    } else {
        return false 
    }
}
```