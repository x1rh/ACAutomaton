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