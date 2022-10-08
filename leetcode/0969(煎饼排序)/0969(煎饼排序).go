func revserse(arr []int) []int {
    for i, j := 0, len(arr)-1; i<j; i, j = i+1, j-1{
        arr[i], arr[j] = arr[j], arr[i]
    }
    return arr 
}

func pancakeSort(arr []int) []int {
    n := len(arr)
    dst := make([]int, n)
    copy(dst, arr)
    sort.Slice(dst, func(i, j int)bool {return dst[i] < dst[j]}) 
    var ans []int

    for i:=0; i<n-1; i++ {
        max := dst[n-i-1]
        idx := 0
        for j:=0; j<n-i; j++ {
            if arr[j] == max {
                idx = j
                break 
            }
        }

        revserse(arr[0:idx+1])
        revserse(arr[0:n-i])
        ans = append(ans, idx+1)
        ans = append(ans, n-i) 
    }
    return ans 
}