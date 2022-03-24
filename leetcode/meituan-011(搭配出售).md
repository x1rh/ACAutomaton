# 题目
[meituan-011. 搭配出售](https://leetcode-cn.com/problems/0JzXQB/)

# 题意

# 思路
贪心。注意到每种组合都必须有衬衫，那衬衫就是切入口。每次选择利润最大的组合即可


```go
package main 

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    var a, b, c, d, e, f, g int 
    r := bufio.NewReader(os.Stdin)
    fmt.Fscan(r, &a, &b, &c, &d, &e, &f, &g)
    
    arr := []struct{cnt, price int}{{a, e}, {b, f}, {c, g}}

    sort.Slice(arr, func(i, j int)bool {
        return arr[i].price > arr[j].price || 
            (arr[i].price==arr[j].price && arr[i].cnt > arr[j].cnt)
    })

    ans := 0 
    for i:=0; i<3&&d>0; i++ {
        if d < arr[i].cnt {
            ans += d * arr[i].price 
            d = 0 
        } else {
            d -= arr[i].cnt 
            ans += arr[i].cnt * arr[i].price 
        }
    }

    fmt.Printf("%d", ans)

}
```