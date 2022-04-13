# 题目
[剑指 Offer 59 - I. 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)

# 题意
滑动窗口GetMax


# 思路
以O(1)时间复杂度实现滑动窗口的GetMax()， 这实际上和以O(1)实现队列的GetMax()没啥区别，属于套路题


```go
func maxSlidingWindow(nums []int, k int) []int {
    n := len(nums)
    q := []int{}
    ans := []int{}
    for i,j:=0,0; j<n; j++ {
        for len(q)!=0 && q[len(q)-1] < nums[j] {
            q = q[:len(q)-1]
        }
        q = append(q, nums[j])

        for j-i+1 > k {
            if q[0] == nums[i] {
                q = q[1:]
            }
             i += 1 
        }
        if j-i+1 == k {
            ans = append(ans, q[0])
        }
    }

    return ans 
}
```