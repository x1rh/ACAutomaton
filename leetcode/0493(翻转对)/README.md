# 题目
[493. 翻转对](https://leetcode.cn/problems/reverse-pairs/)

# 题意
求`i<j && nums[i] > 2*nums[j]`的`元组(i, j)`的个数

# 思路
二维偏序问题，固定了i和j顺序后，使用树状数组解决

```go
type BIT struct {
    d []int 
    n int 
}

func (tree *BIT) add(i, x int) {
    for ; i<=tree.n; i+=(i&(-i)) {
        tree.d[i] += x 
    }
}

func (tree *BIT) query(i int) int{
    res := 0
    for ; i>0; i-=(i&(-i)) {
        res += tree.d[i] 
    }
    return res 
}


func reversePairs(nums []int) int {
    a := make([]int, len(nums))
    n := len(nums)
    copy(a, nums)
    sort.Ints(a)

    tree := BIT{
        d: make([]int, len(nums)+1),
        n: len(nums),
    }

    cnt := 0 
    for i:=0; i<n; i++ {
        idx := sort.SearchInts(a, 2*nums[i]+1)
        cnt += tree.query(n) - tree.query(idx)
        idx = sort.SearchInts(a, nums[i])
        tree.add(idx+1, 1)
    }
    return cnt 
}
```

