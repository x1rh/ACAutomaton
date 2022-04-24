# 题目
[729. 我的日程安排表 I](https://leetcode-cn.com/problems/my-calendar-i/)

# 题意
往日程表在线插入日程，判断要求日程不相交，若相交返回false，否则插入日程并返回true

# 思路1 线段树
因为点的范围太大，且要求在线查询区间是否相交，所以用线段树只能使用动态开点线段树。  

判断区间是否相交的方法： 查询该区间内1的个数是否为0  



```go
const (
    maxn = 2000 * 30  // 注意点个数计算 = 2*1000*log(1000000000)
    EMPTY = 0x3f3f3f3f    // 注意空标记
)

type node struct {
    l, r, x, t int
}

type SegmentTree struct {
    cnt int     
    d [maxn]node  
}

func (st *SegmentTree) up(p int) {
    st.d[p].x = st.d[st.d[p].l].x + st.d[st.d[p].r].x 
}

func (st *SegmentTree) down(p, len int) {
    if st.d[p].l == 0 {
        st.cnt++
        st.d[p].l = st.cnt
        st.d[st.cnt].t = EMPTY
    } 
    if st.d[p].r == 0 {
        st.cnt++
        st.d[p].r = st.cnt
        st.d[st.cnt].t = EMPTY
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
        mid := (l+r)>>1   // notice 
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



type MyCalendar struct {
    tree SegmentTree
}


func Constructor() MyCalendar {
    r := MyCalendar{}
    r.tree.d[1].t = EMPTY;
    r.tree.cnt = 1 
    return r 
}


func (this *MyCalendar) Book(start int, end int) bool {
    if this.tree.query(1, start, end-1, 0, 1000000000) == 0 {
        this.tree.set(1, start, end-1, 0, 1000000000, 1)
        return true 
    } else {
        return false 
    }   
}
```
