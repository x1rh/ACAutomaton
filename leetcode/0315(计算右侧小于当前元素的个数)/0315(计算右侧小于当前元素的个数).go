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