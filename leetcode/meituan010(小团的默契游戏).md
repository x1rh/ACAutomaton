# 题目
[meituan-010. 小团的默契游戏](https://leetcode-cn.com/problems/yqj8Su/)


# 题意

从`[1, m]`中选取l和r，满足l<=r，从数组nums中选取元素x，要求x落在区间`(0, l)`或`(r, m+1)`中，当且仅当所有x单调不减时，认为l和r是一个合法的组合。  

求这样组合的个数

# 思路

- l<=r 且r单调不减，利用这一点可以用二分快速确定r的位置
- 注意r越大，则l和r是合法组合的概率越大。所以最后统计贡献的时候是m-r+1，而不是r-i+1
- 时间复杂度O(m * log m * n) 复杂度严格来说是超时的

```go
package main 

import (
    "bufio"
    "fmt"
    "os"
)


func main() {
    var m, n, ans int 
    r := bufio.NewReader(os.Stdin)
    fmt.Fscan(r, &m, &n)

    arr := make([]int, n)
    for i:=0; i<n; i++ {
        fmt.Fscan(r, &arr[i])
    }


    for i:=1; i<=m; i++ {        
        var l, r int 
        for l, r = i, m; l<=r; {
            mid := (l+r)/2 

            pre := -1
            flag := false 
            
            for _, x := range arr {
                if (0<x&&x<i) || (mid<x&&x<m+1) {
                    if pre <= x {
                        pre = x 
                    } else {
                        flag = true
                        break 
                    }
                } 
            }

            if !flag {
                r = mid -1 
            } else {
                l = mid + 1
            }
        }

        ans += m-l+1
        
    }
    fmt.Printf("%v", ans)
}
```
