# 题目
[448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)




# 思路

```go
func findDisappearedNumbers(nums []int) []int {
    bu := make([]bool, len(nums) + 1)

    for i := range nums {
        bu[nums[i]] = true 
    }

    ans := make([]int, 0)
    for i := range bu {
        if i == 0 {
            continue 
        }
        if !bu[i] {
            ans = append(ans, i)
        }
    }

    return ans 
}
```
