func myAtoi(s string) int {

    pn := 0
    preNumber := false 
    
    max := int((1<<31) - 1 )
    min := -max-1 
    ans := int(0) 
    
    for _, c := range s {
        if preNumber && !unicode.IsDigit(c) {
            break 
        }

        if unicode.IsSpace(c) {
            if pn != 0 {
                break 
            } else {
                continue 
            }
        } else if c == '+' {
            if pn != 0 {
                break 
            }
            pn = 1
        } else if c == '-' {
            if pn != 0 {
                break 
            }
            pn = -1 
        } else if unicode.IsDigit(c) {
            preNumber = true 

            d := int(c-'0')
            
            
            if pn >= 0 {
                ans = ans * 10 + d
                if ans >= max {
                    ans = max 
                    break 
                }
                
            }  else { 
                ans = ans * 10 + d
                if -ans <= min {
                    ans  = min 
                    pn = 0 
                    break 
                }
            } 
        } else {
            break 
        }
    }

    if pn >= 0 {
        return ans 
    } else {
        return -ans 
    }
}
