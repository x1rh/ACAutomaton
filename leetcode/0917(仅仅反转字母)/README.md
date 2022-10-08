# 题目
[917. 仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/)

# 题意
对字符串中下标为`[i_t1, i_t2, i_t3..., i_tn]`的英文字母执行逆置操作，变为`[i_tn, ..., i_t2, i_t1]`，而非英文字母原地不变。

# 思路
记录所有英文字母的下标，然后按下标交换即可。


```go
func reverseOnlyLetters(s string) string {
    var idx []int  

    for i, x := range s {
        if ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z') {
            idx = append(idx, i)
        }
    }

    ans := []byte(s)

    for i, j := 0, len(idx)-1; i < j; i, j = i+1, j-1 {
        ans[idx[i]], ans[idx[j]] = ans[idx[j]], ans[idx[i]]
    }

    return string(ans)
}
```