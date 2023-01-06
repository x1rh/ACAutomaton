package main

const (
	EMPTY  = 0x3f3f3f3f3f3f // 一定要确保这个数用不到
	INF    = 0x3f3f3f3f3f3f
	MaxINF = INF
	MinINF = -INF
)

type Node struct {
	sumv int
	addv int
	setv int
	minv int
	maxv int
	l, r int
}

type SegmentTree struct {
	tree []Node
}

func NewSegmentTree() *SegmentTree {
	st := &SegmentTree{}
	st.tree = append(st.tree, NewNode())
	return st
}

func NewNode() Node {
	return Node{
		sumv: 0,
		minv: MaxINF,
		maxv: MinINF,
		addv: EMPTY,
		setv: EMPTY,
		l:    0,
		r:    0,
	}
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func (st *SegmentTree) pushUp(p int) {
	l := st.tree[p].l
	r := st.tree[p].r
	st.tree[p].sumv = st.tree[l].sumv + st.tree[r].sumv
	st.tree[p].maxv = max(st.tree[l].maxv, st.tree[r].maxv)
	st.tree[p].minv = min(st.tree[l].minv, st.tree[r].minv)
}

func (st *SegmentTree) pushDown(p, Len int) {
	var l, r int
	if st.tree[p].l == 0 { // 利用初始值0判断节点p还没有分配子节点
		l = len(st.tree)
		st.tree[p].l = l
		st.tree = append(st.tree, NewNode())
	}
	if st.tree[p].r == 0 {
		r = len(st.tree)
		st.tree[p].r = r
		st.tree = append(st.tree, NewNode())
	}
	if st.tree[p].setv != EMPTY {
		st.tree[l].setv = st.tree[p].setv
		st.tree[r].setv = st.tree[p].setv
		st.tree[l].minv = st.tree[p].setv
		st.tree[r].minv = st.tree[p].setv
		st.tree[l].maxv = st.tree[p].setv
		st.tree[r].minv = st.tree[p].setv
		st.tree[l].addv = EMPTY
		st.tree[r].addv = EMPTY
		st.tree[l].sumv = st.tree[p].setv * (Len - (Len / 2))
		st.tree[r].sumv = st.tree[p].setv * (Len / 2)
		st.tree[p].setv = EMPTY
	}
	if st.tree[p].addv != EMPTY {
		st.tree[l].addv += st.tree[p].addv
		st.tree[r].addv += st.tree[p].addv
		st.tree[l].sumv += st.tree[p].addv * (Len - Len/2)
		st.tree[r].sumv += st.tree[p].addv * (Len / 2)

		if st.tree[l].minv == MaxINF {
			st.tree[l].minv = st.tree[p].addv
			st.tree[l].maxv = st.tree[p].addv
		} else {
			st.tree[l].minv += st.tree[p].addv
			st.tree[l].maxv += st.tree[p].addv
		}

		if st.tree[r].minv == MaxINF {
			st.tree[r].minv = st.tree[p].addv
			st.tree[r].maxv = st.tree[p].addv
		} else {
			st.tree[r].minv += st.tree[p].addv
			st.tree[r].maxv += st.tree[p].addv
		}

		st.tree[p].addv = EMPTY
	}
}

func (st *SegmentTree) Add(p, l, r, a, b, v int) {
	if a <= l && r <= b {
		st.tree[p].sumv += v * (r - l + 1)
		st.tree[p].addv += v

		if st.tree[p].minv == MaxINF {
			st.tree[p].minv = v
			st.tree[p].maxv = v
		} else {
			st.tree[p].minv += v
			st.tree[p].maxv += v
		}
	} else {
		st.pushDown(p, r-l+1)
		m := (l + r) / 2
		if a <= m {
			st.Add(st.tree[p].l, l, m, a, b, v)
		}
		if m < b {
			st.Add(st.tree[p].r, m+1, r, a, b, v)
		}
		st.pushUp(p)
	}
}

func (st *SegmentTree) Set(p, l, r, a, b, v int) {
	if a <= l && r <= b {
		st.tree[p].setv = v
		st.tree[p].sumv = v * (r - l + 1)
		st.tree[p].addv = EMPTY
		st.tree[p].maxv = v
		st.tree[p].minv = v
	} else {
		st.pushDown(p, r-l+1)
		m := (l + r) / 2
		if a <= m {
			st.Set(st.tree[p].l, l, m, a, b, v)
		}
		if m < b {
			st.Set(st.tree[p].r, m+1, r, a, b, v)
		}
		st.pushUp(p)
	}
}

func (st *SegmentTree) Query(p, l, r, a, b int) int {
	if a <= l && r <= b {
		return st.tree[p].sumv
	} else {
		st.pushDown(p, r-l+1)
		m := (l + r) / 2
		res := 0
		if a <= m {
			res += st.Query(st.tree[p].l, l, m, a, b)
		}
		if m < b {
			res += st.Query(st.tree[p].r, m+1, r, a, b)
		}
		st.pushUp(p)
		return res
	}
}

func (st *SegmentTree) QueryMax(p, l, r, a, b int) int {
	if a <= l && r <= b {
		return st.tree[p].maxv
	} else {
		st.pushDown(p, r-l+1)
		m := (l + r) / 2
		res := -INF
		if a <= m {
			res = max(res, st.QueryMax(st.tree[p].l, l, m, a, b))
		}
		if m < b {
			res = max(res, st.QueryMax(st.tree[p].r, m+1, r, a, b))
		}
		st.pushUp(p)
		return res
	}
}

func (st *SegmentTree) QueryMin(p, l, r, a, b int) int {
	if a <= l && r <= b {
		return st.tree[p].minv
	} else {
		st.pushDown(p, r-l+1)
		m := (l + r) / 2
		res := -INF
		if a <= m {
			res = min(res, st.QueryMax(st.tree[p].l, l, m, a, b))
		}
		if m < b {
			res = min(res, st.QueryMax(st.tree[p].r, m+1, r, a, b))
		}
		st.pushUp(p)
		return res
	}
}
