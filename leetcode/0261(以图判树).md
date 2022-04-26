# 题目
[261. 以图判树](https://leetcode-cn.com/problems/graph-valid-tree/)

# 题意
判断一个图是不是一棵树

# 思路
- 题意规定了输入没有重边和自循环的边
- 判断边构成的图是否有环：如果一条边的两个点在并查集中有同一个祖先，那么加入这条边将导致成环
- 如果一个图没有环，这个图是一个n个节点的树的充要条件是其有n-1条边


```go
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

func validTree(n int, edges [][]int) bool {
    set := &UnionFindSet{}
    Init(set, n)

    for i:=0; i<len(edges); i++ {
        if !set.union(edges[i][0], edges[i][1]) {
            return false 
        }
    }
    
    return len(edges) == n-1
}
```
