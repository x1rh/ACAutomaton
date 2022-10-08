# 题目
[6. Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/)


# 题意
将字符串按Z字排在二维数组里，然后按每行每列输出


# 思路
找规律，观察第一行和最后一行，在行内，两个元素在原始字符串中的间隔为`(numRows-1)*2`， 其余行需要在中间添加一个元素x，认真观察不难找出规律。


```go
func convert(s string, numRows int) string {
    if numRows == 1 {
        return s 
    }

    delta := (numRows-1) * 2
    var ans []byte 
    for i:=0; i<numRows; i++ {
        for j:=i; j<len(s); {
            ans = append(ans, s[j])
            j = j + delta 
            k := j-2*i
            if i==0 || i==numRows-1 {
                continue;
            } else if 0<=k && k < len(s){
                ans = append(ans, s[j-2*i])
            }
        }
    }

    return string(ans)
}
```

时间复杂度：O(n)  
空间复杂度：O(n)  