# 题目
[553. 最优除法](https://leetcode-cn.com/problems/optimal-division/)


# 题意
给一个整数数组添加除号和括号，使得结果最大

# 思路
结果必定是：a/(b/c/d/..../z)

```go
func optimalDivision(nums []int) string {
    if len(nums) == 1 {
        return strconv.Itoa(nums[0])
    } else if len(nums) == 2 {
        return fmt.Sprintf("%d/%d", nums[0], nums[1])
    } else {
        sa := make([]string, len(nums)-1)
        for i := range sa {
            sa[i] = strconv.Itoa(nums[i+1])
        }
        return strconv.Itoa(nums[0]) + "/" + "(" + strings.Join(sa, "/") + ")"
    }
}
```
