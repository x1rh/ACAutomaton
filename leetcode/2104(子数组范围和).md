# 题目
[2104. 子数组范围和](https://leetcode-cn.com/problems/sum-of-subarray-ranges/)


# 题意
定义区间的范围为区间内最大、最小两个数的差

求所有区间的范围和



# 思路
- 维护区间`[i,j]`的最大最小值，然后转移到下一个区间`[i, j+1]`即可
- 时间复杂度`O(n^2)`


```go
type tuple struct {
    x, y int 
}


func subArrayRanges(nums []int) int64 {
    n := len(nums)
    m := make([][]tuple, n)    

    var ans int64 

    for i:=0; i<n; i++ {
        m[i] = make([]tuple, n)
        for j:=i; j<n; j++ {
            if i == j {
                m[i][j].x = nums[i]
                m[i][j].y = nums[i]
            } else {
                m[i][j].x = m[i][j-1].x
                m[i][j].y = m[i][j-1].y 

                if m[i][j].x < nums[j] {
                    m[i][j].x = nums[j]
                } 
                if m[i][j].y > nums[j] {
                    m[i][j].y = nums[j] 
                }
                ans += int64(m[i][j].x - m[i][j].y)
            }
        }
    }
    return ans 
}
```