func maxConsecutiveAnswers(s string, k int) int {
    n := len(s)

    var i, j int 

    cal := func(x byte) int { 
        cnt := 0 
        res := 0 
        for i,j=0,0; j<n; j++{
            if s[j] == x {
                if cnt < k {
                    cnt += 1 
                } else {
                    for ; i<=j; i++ {
                        if s[i] == x {
                            i += 1 
                            break 
                        }
                    }
                }
            } 

            if j-i+1 > res {
                res = j-i+1 
            }
        }
        return res 
    }

    max := func(x, y int) int {
        if x > y {
            return x 
        } else {
            return y 
        }
    }


    return max(cal('T'), cal('F'))
}