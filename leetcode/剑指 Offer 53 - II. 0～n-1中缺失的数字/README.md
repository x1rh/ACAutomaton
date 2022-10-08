# 题目
[剑指 Offer 53 - II. 0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/)


# 思路
答案把排序的数组分为了两个区间，一个是nums[mid]==mid的，另一个是不等的，利用这一点使用二分即可

```go
func missingNumber(nums []int) int {
    var l, r, mid int 

    for l, r=0, len(nums)-1; l<=r; {
        mid = (l+r)/2
        if nums[mid] == mid {
            l = mid + 1 
        } else {
            r = mid - 1 
        }
    }

    return l 
}
```