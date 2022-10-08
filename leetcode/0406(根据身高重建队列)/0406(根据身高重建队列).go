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