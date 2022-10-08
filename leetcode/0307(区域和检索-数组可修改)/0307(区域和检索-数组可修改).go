const (
	maxn = (30000 + 10) << 2
)

type node struct {
	x int // 点的值或者区间和
}

type SegmentTree struct {
	n    int
	tree []node
}

func (st *SegmentTree) pushUp(rt int) {
	st.tree[rt].x = st.tree[rt<<1].x + st.tree[rt<<1|1].x
}

func (st *SegmentTree) Build(arr []int) {
	st.n = len(arr)
    idx := 0 
	st.tree = make([]node, maxn)
	var dfs func(int, int, int)
	dfs = func(rt, l, r int) {
		if l == r {
			st.tree[rt].x = arr[idx]
            idx++
		} else {
			mid := (l + r) >> 1
			dfs(rt<<1, l, mid)
			dfs(rt<<1|1, mid+1, r)
			st.pushUp(rt)
		}
	}
	dfs(1, 1, st.n)
}

func (st *SegmentTree) UpdateOne(rt, idx, l, r, x int) {
	if l == r {
		st.tree[rt].x = x
	} else {
		mid := (l + r) >> 1
		if idx <= mid {
			st.UpdateOne(rt<<1, idx, l, mid, x)
		}
		if mid < idx {
			st.UpdateOne(rt<<1|1, idx, mid+1, r, x)
		}
		st.pushUp(rt)
	}
}

func (st *SegmentTree) Query(rt, a, b, l, r int) int {
	if a <= l && r <= b {
		return st.tree[rt].x
	} else {
		mid := (l + r) >> 1
		res := 0
		if a <= mid {
			res += st.Query(rt<<1, a, b, l, mid)
		}
		if mid < b {
			res += st.Query(rt<<1|1, a, b, mid+1, r)
		}
		return res
	}
}




type NumArray struct {
    st SegmentTree
}

func Constructor(nums []int) NumArray {
    r := NumArray{}
    r.st.Build(nums)
    return r 
}


func (this *NumArray) Update(index int, val int)  {
    this.st.UpdateOne(1, index+1, 1, this.st.n, val)
}


func (this *NumArray) SumRange(left int, right int) int {
    return this.st.Query(1, left+1, right+1, 1, this.st.n)
}