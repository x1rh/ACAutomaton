# 题目
[540. 有序数组中的单一元素](`https://leetcode-cn.com/problems/single-element-in-a-sorted-array/`)


# 题意
在一个不降序排列的整数数组中查找只出现一次的数（其余数全部出现两次）

# 思路
1. 暗示二分
2. 找规律：
    - 只出现一次的那个数会影响之后相同的两个数的下标的奇偶。设目标下标为x
        - 如果mid是偶数，且nums[mid]=nums[mid-1]，则x > mid
        - 如果mid是奇数，且nums[mid]=nums[mid+1]，则x > mid
        - 其余情况 x <= mid

# 代码
Go
```go
func singleNonDuplicate(nums []int) int {
    l := 0
    r := len(nums) - 1
    for ; l<=r; {
        mid := (l+r)/2
        if ((mid-1>=0)&&(mid%2!=0)&&(nums[mid-1]==nums[mid])) || ((mid+1<len(nums))&&(mid%2==0)&&(nums[mid]==nums[mid+1])) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return nums[l];
}
```