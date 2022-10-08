# 题目
[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

# 题意
求大小为k的滑动窗口中的最大值

# 思路
堆，具体细节为，不需要限制堆的大小为k，只需要保证堆顶元素在当前滑动窗口中即可，若不在则pop


```go
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
```