# 题目
[315. 计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self/)

# 题意
对于每个i，求满足`i<j && nums[i] > nums[j]`的j的个数

# 思路
二维偏序问题

```go
import (
    "sort"
)

type BIT struct {
    d []int 
    n int 
}

func (tree *BIT) add(i, x int) {
    for ; i<=tree.n; i+=(i&(-i)) {
        tree.d[i] += x 
    }
}

func (tree *BIT) query(i int) int {
    res := 0
    for ; i>0; i-=(i&(-i)) {
        res += tree.d[i] 
    }
    return res 
}

func countSmaller(nums []int) []int {
    n := len(nums)
    a := make([]int, n)
    copy(a, nums)
    sort.Ints(a)

    tree := &BIT{
        d: make([]int, n+1),
        n: n, 
    }

    r := make([]int, n)
    for i:=n-1; i>=0; i-- {
        idx := sort.SearchInts(a, nums[i])
        r[i] = tree.query(idx)
        tree.add(idx+1, 1)
    }
    return r
}
```

