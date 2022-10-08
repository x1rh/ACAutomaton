# 题目
`https://leetcode-cn.com/problems/sum-of-unique-elements/`

# 题意
求只出现一次的元素的和

# 思路
用map记录次数，遍历一次map求和即可。

```go
func sumOfUnique(nums []int) int {
    mp := make(map[int]int)
    for _, x := range nums {
        mp[x] += 1
    }

    var ans int = 0
    for k, v := range mp {
        if v == 1 {
            ans += k
        }
    }

    return ans
}
```