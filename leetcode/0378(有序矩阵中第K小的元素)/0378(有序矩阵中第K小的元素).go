import (
    "container/heap"
    "sort"
)

type hp struct{
    sort.IntSlice
}

func (h *hp) Less(i, j int) bool {
    return h.IntSlice[i] > h.IntSlice[j]
}

func (h *hp) Push(x interface{}) {
    h.IntSlice = append(h.IntSlice, x.(int))
}

func (h *hp) Pop() interface{} {
    r := h.IntSlice[len(h.IntSlice)-1]
    h.IntSlice = h.IntSlice[0:len(h.IntSlice)-1]
    return r 
}

func kthSmallest(matrix [][]int, k int) int {
    h := &hp{}
    for _, r := range matrix {
        for _, c := range r {
            if len(h.IntSlice) < k {
                h.Push(c)
                if len(h.IntSlice) == k {
                    heap.Init(h)
                }
            } else {
                if c <= h.IntSlice[0] {
                    heap.Pop(h)
                    heap.Push(h, c)
                }
            }
        }
    }
    return h.IntSlice[0]
}