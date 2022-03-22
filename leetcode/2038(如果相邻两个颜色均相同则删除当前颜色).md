# 题目
[2038. 如果相邻两个颜色均相同则删除当前颜色](https://leetcode-cn.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)


# 题意
大于2个的连续'A'串可以删除到只剩下两个，B串同理。

求alice是否能赢bob


# 思路
因为不能全部删除，必须剩下两个的缘故，所以不存在连通的问题。
等价于求alice和bob最多能删除几个A或B

```go
func winnerOfGame(colors string) bool {
    i := 0 
    n := len(colors)

    a := 0
    b := 0 

    for i < n {
        var j int 
        if colors[i] == 'A' {
            for j=i; j<n&&colors[j]=='A'; j++ {}

            if j-i>2 {
                a += j-i-2
            }
        } else {
            for j=i; j<n&&colors[j]=='B'; j++ {}
            if j-i>2 {
                b += j-i-2
            }
        }
        i = j 
    }

    return a > b  
}
```