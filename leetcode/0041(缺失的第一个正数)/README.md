# 题目
[41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)

# 题意
找到数组中缺失的第一个正数


# 思路

- 负数不需要考虑
- 缺失的第一个正数，最小值是1，最大值是n+1（大于n的正数对答案没有贡献）
- 原地哈希：将`nums[i]`放到`nums[nums[i]-1]`，而原本在下标nums[i]-1的值，放到其对应的位置
- 从0到n-1遍历，如果nums[i]!=i+1说明缺失的第一个正数是i+1
- 注意n+1

```go
func firstMissingPositive(nums []int) int {
    n := len(nums)
    for i:=0; i<n; i++ {
        for nums[i]>0 && nums[i]<n && nums[i] != nums[nums[i]-1] {
            nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i] 
        }
    }
    for i:=0; i<n; i++ {
        if i+1 != nums[i] {
            return i+1 
        }
    }
    return n+1 
}
```