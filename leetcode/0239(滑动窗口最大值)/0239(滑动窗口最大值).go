type node struct {
    v, i int 
}

type hp struct {
    data []node 
}

func (h *hp) Len() int {return len(h.data)}
func (h *hp) Less(i, j int) bool {
    return h.data[i].v > h.data[j].v || (h.data[i].v == h.data[j].v && h.data[i].i < h.data[j].i)
}
func (h *hp) Swap(i, j int) {
    h.data[i], h.data[j] = h.data[j], h.data[i] 
}

func (h *hp) Push(v interface{}) {
    h.data = append(h.data, v.(node))
}

func (h *hp) Pop() interface{}{
    last := h.data[len(h.data)-1]
    h.data = h.data[:len(h.data)-1]
    return last 
}


func maxSlidingWindow(nums []int, k int) []int {

    q := hp{}
    ans := []int{}

    for i := range nums {
        if i < k-1 {
            q.Push(node{v: nums[i], i: i })
        } else {
            if i == k-1 {
                heap.Init(&q)
            } 

            heap.Push(&q, node{v :nums[i], i: i})

            for q.data[0].i <= i-k {
                heap.Pop(&q)
            }
            ans = append(ans, q.data[0].v)
        }
    }
    return ans 
}