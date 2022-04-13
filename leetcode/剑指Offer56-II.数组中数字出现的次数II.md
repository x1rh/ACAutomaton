# 题目
[剑指 Offer 56 - II. 数组中数字出现的次数 II](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)

# 题意
在一个数组中，存在一个只出现一次的数，和其他出现了3次的数，求出这个只出现了一次的数


# 思路

分别统计每一个二进制位上1的个数cnt，如果cnt是3的倍数，那么这个数位对答案没有贡献。以此类推


```go
func singleNumber(nums []int) int {
    ans := 0 
    for i:=30; i>=0; i-- {
        cnt := 0 
        for j := range nums {
            cnt += (nums[j]>>i) & 1 
        }
        ans <<= 1 
        cnt %= 3 
        ans += cnt 
    }
    return ans 
}
```