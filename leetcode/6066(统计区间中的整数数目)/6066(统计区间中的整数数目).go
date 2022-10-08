const (
    L = 1 
    R = int(1e9)
    EMPTY = 0x3f3f3f3f    
)

type node struct {
    l, r, x, t int
}

type SegmentTree struct {
    cnt int     
    d []node  
}

func (st *SegmentTree) up(p int) {
    st.d[p].x = st.d[st.d[p].l].x + st.d[st.d[p].r].x 
}

func (st *SegmentTree) down(p, len int) {
    if st.d[p].l == 0 {
        st.cnt++
        st.d = append(st.d, node{t: EMPTY})
        st.d[p].l = st.cnt
    } 
    if st.d[p].r == 0 {
        st.cnt++
        st.d[p].r = st.cnt
        st.d = append(st.d, node{t: EMPTY})
    }

    if st.d[p].t != EMPTY {
        ls, rs := st.d[p].l, st.d[p].r 
        st.d[ls].t = st.d[p].t 
        st.d[rs].t = st.d[p].t 
        st.d[ls].x = (len - len/2) * st.d[p].t  
        st.d[rs].x = len/2 * st.d[p].t 
        st.d[p].t = EMPTY
    }
}

func (st *SegmentTree) set(p, a, b, l, r, x int) {
    if a<=l && r<=b {
        st.d[p].t = x 
        st.d[p].x = (r-l+1) * x 
    } else {
        mid := (l+r)>>1   
        st.down(p, r-l+1)
        if a<=mid {
            st.set(st.d[p].l, a, b, l, mid, x)
        }
        if mid<b {
            st.set(st.d[p].r, a, b, mid+1, r, x)
        }
        st.up(p)
    }
}

func (st *SegmentTree) query(p, a, b, l, r int) int {
    if a<=l && r<=b {
        return st.d[p].x 
    } else {
        mid := (l+r) / 2 
        st.down(p, r-l+1)
        res := 0 
        if a<=mid {
            res += st.query(st.d[p].l, a, b, l, mid)
        }
        if mid<b {
            res += st.query(st.d[p].r, a, b, mid+1, r)
        }
        return res 
    }
}



type CountIntervals struct {
    tree SegmentTree
}


func Constructor() CountIntervals {
    r := CountIntervals{}
    r.tree.d = make([]node, 2)
    r.tree.d[1].t = EMPTY;
    r.tree.cnt = 1 
    return r 
}


func (this *CountIntervals) Add(left int, right int)  {
    this.tree.set(1, left, right, 1, R, 1)
}


func (this *CountIntervals) Count() int {
    return this.tree.d[1].x 
}



/**
 * Your CountIntervals object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(left,right);
 * param_2 := obj.Count();
 */
