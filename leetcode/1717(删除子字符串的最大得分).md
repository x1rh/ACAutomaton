# 题目
[1717. 删除子字符串的最大得分](https://leetcode-cn.com/problems/maximum-score-from-removing-substrings/)

# 题意
删除ab获得x分，删除ba获得y分，求最大分数

# 思路
- 设得分最大的是p，p的取值是ab或ba
- 非字母a和b都相当于分割符号，理解了这一点后，将原来的串转换为多个只包含a和b的串
- 结论1：最多删除次数=`min(count('b'), count('b'))`
- 结论2：贪心，优先处理p，如果当前字符无法与栈顶元素构成p，那么入栈。这样，最后栈中剩下的字符的形式只可能是aaaaaabbbbbb，或者bbbbbbbaaaaa

```go
func maximumGain(s string, x int, y int) int {
    n := len(s)
    ans := 0 

    p1 := "ab"
    p2 := "ba"
    if x < y {
        p1, p2 = p2, p1 
        x, y = y, x 
    } 

    for i,j:=0,0; j<n; {
        for ; i<n && s[i] != 'a' && s[i] != 'b'; i++ {}
        for j=i; j<n && (s[j] == 'a' || s[j] == 'b' ); j++ {}

        ts := s[i:j]
        stack := []byte{}
        for k:=0; k<len(ts); k++ {
            if ts[k] == p1[1] && len(stack) > 0 && stack[len(stack)-1] == p1[0] {
                stack = stack[0:len(stack)-1]
                ans += x 
            } else {
                stack = append(stack, ts[k])
            }
        }
        for l, r := 0, len(stack) - 1; l < r; l, r = l + 1, r - 1 {
            if stack[l] == stack[r] {
                break 
            } else {
                ans += y 
            }
        }
        stack = nil 
        i = j 
    }
    return ans 
}
```