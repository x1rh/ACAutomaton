# 题目
[406. 根据身高重建队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)

# 题意
给出(hi,ki)序列，将其恢复到原来的位置

# 思路
二分+线段树动态维护前缀和，时间复杂度`O(n*log(n)*log(n))`

设一开始时在区间`[1,n]`上有n个空位，n个人按规则占位。

按h排序，h相等的时候k大的排前面（排前面的意思是先处理，贪心思想）
每次取最小的h，这使得后续的h都比之前的h大。

线段树维护这n个空位，我们可以以O(log(n))的复杂度求出[1,i]这个区间内有多少个空位，而第j项 (hj, kj)需要kj+1个空位。

二分查找插入的位置即可。



```go
var sumv []int 
const maxn = 2010 << 2 

func up(rt int) {
    sumv[rt] = sumv[rt<<1] + sumv[rt<<1|1]
}

func build(rt, l, r int) {
    if l == r {
        sumv[rt] = 1 
    } else {
        mid := (l+r)>>1
        build(rt<<1, l, mid)
        build(rt<<1|1, mid+1, r)
        up(rt)
    }
}


func update(rt, a, b, l, r, x int) {
    if a<=l && r<=b {
        sumv[rt] = x 
    } else {
        mid := (l+r)>>1
        if a<=mid {
            update(rt<<1, a, b, l, mid, x)
        }
        if mid<b {
            update(rt<<1|1, a, b, mid+1, r, x)
        }
        up(rt)
    }
} 

func query(rt, a, b, l, r int) int {
    if a<=l && r<=b {
        return sumv[rt]
    } else {
        mid := (l+r)>>1
        res := 0 
        if a<=mid {
            res += query(rt<<1, a, b, l, mid)
        } 
        if mid<b {
            res += query(rt<<1|1, a, b, mid+1, r)
        }
        return res 
    }
}



func reconstructQueue(people [][]int) [][]int {
    n := len(people)
    sumv = make([]int, maxn)

    sort.Slice(people, func(i, j int) bool {
        return people[i][0]<people[j][0] || (people[i][0]==people[j][0] && people[i][1]>people[j][1])
    })

    build(1, 1, n)

    ans := make([][]int, n)
    for i:=0; i<n; i++ {
        l, r := 1, n
        for l<=r {
            mid := (l+r)/2

            if query(1, 1, mid, 1, n) >= people[i][1]+1 {
                r = mid - 1 
            } else {
                l = mid + 1
            }
        }
        update(1, l, l, 1, n, 0)
        ans[l-1] = []int{people[i][0], people[i][1]}
    }

    return ans 
}
```