# 题目
[442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)

# 思路
同 [0041-缺失的第一个正数](./0041(缺失的第一个正数).md)

```go
func findDuplicates(nums []int) []int {
    n := len(nums)
    for i:=0; i<n; i++ {
        for nums[i] != nums[nums[i]-1] {
            nums[i], nums[nums[i]-1]  = nums[nums[i]-1], nums[i] 
        }
    }

    ans := []int{}
    for i:=0; i<n; i++ {
        if i != nums[i] - 1 {
            ans = append(ans, nums[i])
        }
    }
    return ans 
}
```
