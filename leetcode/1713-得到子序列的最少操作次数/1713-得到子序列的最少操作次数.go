func minOperations(target []int, arr []int) int {
    mp := make(map[int]int)
    m := len(target)
    n := len(arr)
    for i:=0; i<m; i++ {
        mp[target[i]] = i
    }

    d := []int{}
    for i:=0; i<n; i++ {
        v, ok := mp[arr[i]]
        if !ok {
            continue 
        }
        if len(d) == 0 {
            d = append(d, v)
        } else {
            if v > d[len(d)-1] {
                d = append(d, v)
            } else {
                idx := sort.SearchInts(d, v)
                d[idx] = v 
            }
        }
    }
    return m - len(d) 
}