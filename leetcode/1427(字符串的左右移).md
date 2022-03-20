# 题目
[1427. 字符串的左右移](https://leetcode-cn.com/problems/perform-string-shifts/)

# 题意
将字符串每个字符循环向左或右移动指定长度


# 思路
```go
func stringShift(s string, shift [][]int) string {

    str := []byte(s)

    for i := range shift {
        step := shift[i][1] % len(s)
        if step==0{
            continue 
        }

        if shift[i][0] == 0 {
           str = append(str, str[0:step]...)
           str = str[step:len(str)] 
        } else {
            pre := str[len(str)-step:len(str)]
            str = str[0:len(str)-step]
            str = append(pre, str...)
        }
    }

    return string(str)
}
```