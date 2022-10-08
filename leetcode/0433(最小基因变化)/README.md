# 题目
[433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)


# 题意
求字符串从start到end的最小次数，每次只能变化一个字符，且变化后的字符必须在所给的列表中出现。

# 思路
bfs，中间状态若代价更小，可重复进入，并更新代价。

```go
type node struct{
    x string 
    c int 
}

func minMutation(start string, end string, bank []string) int {
    if start == end {
        return 0 
    }

    d := []byte{'A', 'C', 'G', 'T'}
    db := make(map[string]bool)
    for i := range bank {
        db[bank[i]] = true 
    }

    cnt := make(map[string]int)     
    q := []node{{start, 0}}
    cnt[start] = 0 

    for len(q) > 0 {
        fr := q[0]
        if fr.x == end {
            return fr.c 
        }
        q = q[1:len(q)]

        arr := []byte(fr.x)
        for i := range arr {
            backup := arr[i]
            for j := range d {
                if d[j] == backup {
                    continue 
                }
                arr[i] = d[j] 
                x := string(arr)
                _, ok := db[x]
                c, ok2 := cnt[x]             
                if ok {
                    if ok2 && fr.c+1 < c{
                        cnt[x] = fr.c+1
                        q = append(q, node{x,fr.c+1})
                    } else if !ok2 {
                        cnt[x] = fr.c+1
                        q = append(q, node{x,fr.c+1})
                    }
                }
            }
            arr[i] = backup 
        }

    }
     
    return -1 
}
```