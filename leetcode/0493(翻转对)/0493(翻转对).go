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