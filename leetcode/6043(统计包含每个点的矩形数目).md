# 题目
[6043. 统计包含每个点的矩形数目](https://leetcode-cn.com/problems/count-number-of-rectangles-containing-each-point/)

# 题意
给出一些矩阵，然后给出一些点，询问每个点在多少个矩阵内。


# 思路
- 这中问题属于二维偏序问题，二维偏序问题使用树状数组可以很方便解决，大体思路为，先排序，然后按排序的顺序遍历（这样就固定了一维x），另一维y使用树状数组动态维护。
- 本题中，先按x排序，再按y排序。需要把查询的点放进去一起排序以保持统一的顺序。
- 本题需要从后往前遍历，因为包含查询点 `p` 的矩阵排序后在 `p` 的右边
- 使用额外的字段记录查询点`p`在原数组中的位置。
- 表示矩阵的点 `q` 赋予一个很大的值 `c`，在x和y相同的情况下，把`c`大的排后面（这样遇到查询点的时候，保证表示矩阵的点已经插入）
- 遍历时我们保证了`px <= qx`, 那么在树状数组中，查询`py <= qy`的点的个数，即我们所求的答案。
- 本题的y不需要离散化，因为y很小。

```go
const (
    inf = 0x3f3f3f3f 
)

type tuple struct {
    x, y, c int 
}

type BIT struct {
    d []int 
    n int 
}

func (tree *BIT) update(idx, x int) {
    for i:=idx; i<tree.n; i+=(i&(-i)) {
        tree.d[i] += x 
    }
}

func (tree *BIT) query(idx int) int {
    r := 0 
    for i:=idx; i>0; i-=(i&(-i)) {
        r += tree.d[i] 
    }
    return r 
}

func countRectangles(rect [][]int, ps [][]int) []int {
    

    arr := []tuple{}
    for i:=0; i<len(rect); i++ {
        arr = append(arr, tuple{rect[i][0], rect[i][1], inf})
    }

    for i:=0; i<len(ps); i++ {
        arr = append(arr, tuple{ps[i][0], ps[i][1], i})
    }

    sort.Slice(arr, func(i, j int) bool {
        if arr[i].x < arr[j].x {
            return true 
        } else if arr[i].x == arr[j].x {
            if arr[i].y < arr[j].y {
                return true  
            } else if arr[i].y == arr[j].y {
                return arr[i].c < arr[j].c
            } else {
                return false  
            }
        } else {
            return false 
        }
    })

    tree := &BIT{d: make([]int, 101), n: 101}

    ans := make([]int, len(ps))
    for i:=len(arr)-1; i>=0; i-- {
        if arr[i].c != inf {
            ans[arr[i].c] = tree.query(100) - tree.query(arr[i].y-1) 
        } else {
            tree.update(arr[i].y, 1)
        }
    }

    return ans 
}
```
