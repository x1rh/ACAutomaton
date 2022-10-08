# 题目
[剑指 Offer 45. 把数组排成最小的数](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)

# 题意
对一个整数数组中的数进行排列，使得排列后组成的数最小

# 思路
设两个整数字符串x、y，那么如果xy > yx, 那么我们把x排在y前面


```go
func minNumber(nums []int) string {
    arr := make([]string, len(nums))
    for i:=0; i<len(nums); i++ {
        arr[i] = strconv.Itoa(nums[i])
    }

    sort.Slice(arr, func(i, j int)bool {
        if arr[i]+arr[j] < arr[j]+arr[i] {
            return true 
        } else {
            return false 
        }
    })

    return strings.Join(arr, "")
}
```
