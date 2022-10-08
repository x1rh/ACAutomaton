func isOneBitCharacter(bits []int) bool {
    i := 0
    n := len(bits)
    ans := true

    for i< n - 1 {
        if bits[i] == 1 {
            if i+1<n-1 {
                i += 2           
            } else {
                ans = false
                break 
            }
        } else {
            i += 1
        } 
    }
    return ans 
}