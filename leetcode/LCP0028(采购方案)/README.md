# 题目
[LCP 28. 采购方案](https://leetcode-cn.com/problems/4xy4Wx/)


# 题意
从一个数组中选出两个和小于等于target的数，问有多少种组合


# 思路
排序+二分

```go
func purchasePlans(nums []int, target int) int {
    sort.Ints(nums)

    n := len(nums)

    ans := 0 

    for i := range nums {
        l := i + 1
        r := n - 1 
        for ; l<=r; {
            mid := (l+r)/2

            if nums[mid] + nums[i] <= target {
                l = mid + 1
            } else {
                r = mid - 1 
            }
        }

        ans = (ans + r - i ) % 1000000007
    }

    return ans 
}

```