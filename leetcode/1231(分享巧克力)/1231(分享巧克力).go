func check(arr []int, avg int) int {
    
    cnt := 0 
    cur := 0 

    for i := range arr {
        cur += arr[i] 
        if cur >= avg {
            cnt += 1
            cur = 0 
        }
    }
    return cnt 
}


func maximizeSweetness(sweetness []int, k int) int {
    sum := 0

    for i := range sweetness {
        sum += sweetness[i]
    }

    l := 0 
    r := sum / (k+1)

    for ; l <= r ; {
        mid := (l+r)/2
        if check(sweetness, mid) >= k+1 {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    return r
}