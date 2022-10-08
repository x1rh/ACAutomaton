# 题目
[1060. 有序数组中的缺失元素](https://leetcode-cn.com/problems/missing-element-in-sorted-array/)

# 题意
有序数组，每两个元素之间，若不连续则存在缺失元素。求第k个缺失元素

# 思路一：暴力
注意答案落在最后一个元素右边区间时的情况

```go
func missingElement(nums []int, k int) int {
    for i:=1; i<len(nums); i++ {
        delta := nums[i] - nums[i-1] - 1 
        if delta < k {
            k -= delta 
        } else {
            return nums[i-1] + k
        }
    }

    if k > 0 {
        return nums[len(nums)-1] + k 
    }

    return -1 
}
```



# 思路二：二分
- 缺失的元素的个数是有序递增的，基于这一点可以用二分。
- 此外就是对缺失元素的计算，参考`func missing()`
- 对答案的计算

```go
func missing(nums []int, idx int) int {
    return nums[idx] - nums[0] - idx 
}


func missingElement(nums []int, k int) int {
    l := 0
    r := len(nums) - 1
    mid := 0
    for ; l<=r; {
        mid = (l+r)/2
        if missing(nums, mid) < k {
            l = mid + 1
        } else {
            r = mid - 1 
        }
    }

    return nums[r] + (k - missing(nums, r))    
}
```