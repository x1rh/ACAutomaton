func maximumGain(s string, x int, y int) int {
    n := len(s)
    ans := 0 

    p1 := "ab"
    p2 := "ba"
    if x < y {
        p1, p2 = p2, p1 
        x, y = y, x 
    } 

    for i,j:=0,0; j<n; {
        for ; i<n && s[i] != 'a' && s[i] != 'b'; i++ {}
        for j=i; j<n && (s[j] == 'a' || s[j] == 'b' ); j++ {}

        ts := s[i:j]
        stack := []byte{}
        for k:=0; k<len(ts); k++ {
            if ts[k] == p1[1] && len(stack) > 0 && stack[len(stack)-1] == p1[0] {
                stack = stack[0:len(stack)-1]
                ans += x 
            } else {
                stack = append(stack, ts[k])
            }
        }
        for l, r := 0, len(stack) - 1; l < r; l, r = l + 1, r - 1 {
            if stack[l] == stack[r] {
                break 
            } else {
                ans += y 
            }
        }
        stack = nil 
        i = j 
    }
    return ans 
}