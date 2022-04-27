## 1. 切片声明与字面量初始化
```go
var dx = []int{0, 0, 1, -1}
dx := []int{0, 0, 1, -1}
```

## 2. 二维切片声明与初始化
```go
matrix := make([][]int, m)
for i:=0; i<m; i++{
    matrix[i] = make([]int, n)
}
```

## 3. 切片复制
```go
copy(destination, source)
```

## 4. 二维数组复制
```go
for i:=0; i<m; i++ {
    copy(matrix[i], source[i]);
}
```

## 5. 闭包函数中递归使用该函数
```go
var dfs func(g [][]int, i, j, t int)
dfs := func(g [][]int, i, j, t int) {
    ....
    dfs(g, i, j, t)
}
```

## 6. 结构体数组排序
```go
arr := []struct{x byte; cnt int}{{'a', a}, {'b', b}, {'c', c}}
sort.Slice(arr, func(i, j int) bool {return arr[i].cnt > arr[j].cnt})
```

## 7. 结构体数组初始化
```go
var dirs = []struct{ x, y int }{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
```

## 8. 处理输入输出

### 8.1 方式1，使用`fmt.Scanln()`, `fmt.Scan()`, `fmt.Scanf()`
```go
package main
import (
    "fmt"
)

func main(){
    var T int
    var s string
    fmt.Scanln(&T)
    for i:=0;i<T;i++{
        fmt.Scanln(&s)
        fmt.Println(T, s)
    }
}
```

## 8.2 方式2，使用`bufio` + `fmt.Fscan()`
- 推荐
- 使用缓冲区，提高io效率
- `fmt.Fscan()`会处理掉间隔的空格和换行符
```go
import (
    "bufio"
    "fmt"
    "os"
)

var m, n, v int
r := bufio.NewReader(os.Stdin)
fmt.Fscan(r, &m, &n)

for i:=0; i<n; i++{
    fmt.Fscan(r, &v)
}
```


## 9. 字符串中字符判断
- 判断是否为字母： `unicode.IsLetter(v)`
- 判断是否为十进制数字： `unicode.IsDigit(v)`
- 判断是否为数字： `unicode.IsNumber(v)`
- 判断是否为空白符号： `unicode.IsSpace(v)`
- 判断是否为Unicode标点字符: `unicode.IsPunct(v)`
- 判断rune是否大写：`unicode.IsUpper()`
- 判断rune是否小写：`unicode.IsLower()`


## 10. 数字和字符串相互转换
- 数字转字符串：`strconv.Itoa()`，无需错误处理
- 字符串转数字：`strconv.Atoi()`, 需要错误处理

## 11. 去除前后空格
- `strings.Trim(s, " ")`
- `strings.TrimLeft(s, " ")`
- `strings.TrimRight(s, " ")`

## 12. 堆

参考[leetcode239官方golang题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/)


```go
import "container/heap"

var a []int
type hp struct{ sort.IntSlice }
func (h hp) Less(i, j int) bool  { return a[h.IntSlice[i]] > a[h.IntSlice[j]] }
func (h *hp) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() interface{}   { a := h.IntSlice; v := a[len(a)-1]; h.IntSlice = a[:len(a)-1]; return v }

func maxSlidingWindow(nums []int, k int) []int {
    a = nums
    q := &hp{make([]int, k)}
    for i := 0; i < k; i++ {
        q.IntSlice[i] = i
    }
    heap.Init(q)

    n := len(nums)
    ans := make([]int, 1, n-k+1)
    ans[0] = nums[q.IntSlice[0]]
    for i := k; i < n; i++ {
        heap.Push(q, i)
        for q.IntSlice[0] <= i-k {
            heap.Pop(q)
        }
        ans = append(ans, nums[q.IntSlice[0]])
    }
    return ans
}
```

参考2：[378. 有序矩阵中第 K 小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)
```go
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
```


需要实现接口：
```go
type Interface interface {
	sort.Interface
	Push(x interface{}) 
	Pop() interface{}   
}

type Interface interface {
	Len() int
	Less(i, j int) bool
	Swap(i, j int)
}
```

- 堆操作对下标数组进行操作，最小化复制、交换的代价，且使用sort.IntSlice，减少接口的实现
- container/heap包中的Pop()操作将堆顶元素交换到数组最后一个并返回，执行pushdown；所以我们在实现接口时得照这样实现。
- Push操作在堆中也是放到数组最后一个，然后pushup；所以实现接口时直接append到末尾
- 注意Init()时传递指针，上面那个例子是因为使用了[]int
- 注意用法，全部都需要用heap包中的方法进行操作，例如`heap.Init(h)`, `heap.Push(h, x)`, `heap.Pop(h)`

ps: 没有泛型写个堆都这么麻烦。。。刚出的泛型不知道还要多少年改写这些库


# 13. 二分查找

```go
idx := sort.Search(len(arr), func(i int)bool{return arr[i]<key})
```

返回使得`f(i)`为`true`的第一个i。但需要注意，我们要实现的是`大于号`或者`大于等于号`。看下面例子：

```go
package main

import (
	"fmt"
	"sort"
)

func main() {
	a := []int{1, 2, 3, 4, 5}
	i := sort.Search(len(a), func(ii int) bool{ return a[ii]<2})       // i=5, 你以为i=0？
	j := sort.Search(len(a), func(ii int) bool{ return a[ii]<=2})      // j=5
	k := sort.Search(len(a), func(ii int) bool{ return a[ii]>2})       // k=2
	l := sort.Search(len(a), func(ii int) bool{ return a[ii]>=2})      // l=1
    m := sort.Search(len(a), func(ii int) bool{ return a[ii]<0})       // m=5, 注意
	fmt.Println(i, j, k, l, m)
}
```

看源代码可以发现，二分采用的是左闭右开的写法，当`f(i)`为false时，`l=mid+1`。

基于以上，我们不需要考虑二分查找到下标-1，二分查找永远只可能在闭区间：`[0, n]`中

# 14. 实现unique()
- 要求`A[]`已排序
- 时间复杂度O(n)

```go
func unique(A []int) []int {
    j := 0
    for i:=1; i<len(A); i++ {
        if A[i] != A[j] {
            j++
            if j < i {
                A[i], A[j] = A[j], A[i] 
            }
        }
    }
    return A[:j+1]
}
```




