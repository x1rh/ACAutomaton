type BIT struct {
    tree []int 
    n int 
}

func build(tree *BIT, n int) {
    tree.n = n
    tree.tree = make([]int, n+1)
}

func (tree *BIT) update(index, x int) {
    for i:=index; i<=tree.n; i+=(i&(-i)) {
        tree.tree[i] += x 
    }
}

func (tree *BIT) query(index int) int {
    res := 0 
    for i:=index; i>0; i-=(i&(-i)) {
        res += tree.tree[i]
    }
    return res 
}

func reversePairs(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    
    tree := &BIT{}
    arr := make([]int, len(nums))

    copy(arr, nums)
    sort.Slice(arr, func(i, j int) bool{return arr[i] < arr[j]})
    
    build(tree, len(arr))
    
    ans := 0
    for i:=0; i<len(nums); i++ {
        idx := sort.Search(len(arr), func(j int) bool {return arr[j]>nums[i]})
        ans += tree.query(len(arr)) - tree.query(idx)
        tree.update(idx, 1)
    }
    return ans 
}