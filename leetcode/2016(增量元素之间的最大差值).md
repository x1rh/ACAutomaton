# 题目
[2016. 增量元素之间的最大差值](https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/)


# 题意
求一个数组中，满足`0<=i<j<n` 且 `nums[j] > nums[i]`这两个条件的`max(nums[j] - nums[i])`


# 思路

动态维护一个最小值nums[i], i<j 即可

```go
func maximumDifference(nums []int) int {
    n := len(nums)
    min := nums[0] 
    ans := -1

    for i:=1; i<n; i++ {
        if nums[i] > min {
            if nums[i] - min > ans {
                ans = nums[i] - min 
            }
        } else {
            min = nums[i]
        }
    }
    return ans 
}
```


暴力：
```go
func maximumDifference(nums []int) int {
    n := len(nums)
    ans := -1

    for i:=0; i<n; i++ {
        for j:=i+1; j<n; j++ {
            if nums[j] > nums[i] && nums[j]-nums[i] > ans {
                ans = nums[j] - nums[i]
            }
        }
    }

    return ans 

}
```