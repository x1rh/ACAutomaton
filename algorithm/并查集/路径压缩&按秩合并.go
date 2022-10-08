type UnionFindSet struct {
    fa, rank []int
}

func Init(s *UnionFindSet, n int) {
    s.fa = make([]int, n)
    s.rank = make([]int, n)
    for i:=0; i<n; i++ {
        s.fa[i] = i;
        s.rank[i] = 1;
    }
}

func (s *UnionFindSet) find(x int) int {
    if s.fa[x] == x {
        return x 
    } else {
        s.fa[x] = s.find(s.fa[x])
        return s.fa[x];
    }
}

func (s *UnionFindSet) union(x, y int) bool {
    px := s.find(x)
    py := s.find(y)
    if px != py {
        if s.rank[px] <= s.rank[py] {
            s.fa[px] = py
            if s.rank[px] == s.rank[py] {
                s.rank[py] += 1 
            }
        } else {
            s.fa[py] = px 
        }
        return true
    } else {
        return false 
    }
}