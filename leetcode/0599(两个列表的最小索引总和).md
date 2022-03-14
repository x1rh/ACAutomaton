# 题目
[599. 两个列表的最小索引总和](https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/)

# 题意
找出两个数组中相同的字符串，要求两个字符串下标之和最小

# 思路
暴力循环

```go
func findRestaurant(list1 []string, list2 []string) []string {
    x := 0x3f3f3f3f
    y := 0x3f3f3f3f 
    var ans []string 

    for i:=0; i<len(list1); i++ {
        for j:=0; j<len(list2); j++ {
            if list1[i] == list2[j] && i+j<=x+y {
                if i+j < x+y {
                    ans = nil 
                    ans = append(ans, list1[i])
                    x = i
                    y = j 
                } else {
                    ans = append(ans, list1[i])
                }
            }
        }
    }

    return ans 
}
```
