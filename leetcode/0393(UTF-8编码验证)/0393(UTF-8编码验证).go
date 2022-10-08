func check(x, offset, target int) bool {
    y := 1<<(offset-1)

    if x & y == y {
        if target == 1 {
            return true 
        } else {
            return false 
        }
    } else {
        if target == 0 {
            return true 
        } else {
            return false 
        }
    }
}

func validUtf8(data []int) bool {
    n := len(data)
    for i:=0; i<n; {
        if check(data[i], 8, 1) {
            if i+3<n && check(data[i], 7, 1) && 
                check(data[i], 6, 1) && 
                check(data[i], 5, 1) && 
                check(data[i], 4, 0) &&
                check(data[i+1], 8, 1) && 
                check(data[i+1], 7, 0) &&
                check(data[i+2], 8, 1) && 
                check(data[i+2], 7, 0) &&
                check(data[i+3], 8, 1) && 
                check(data[i+3], 7, 0) {
                    i+= 4
            } else if i+2<n && check(data[i], 7, 1) && 
                check(data[i], 6, 1) && 
                check(data[i], 5, 0) && 
                check(data[i+1], 8, 1) && 
                check(data[i+1], 7, 0) &&
                check(data[i+2], 8, 1) && 
                check(data[i+2], 7, 0) {
                    i+=3
            } else if i+1<n && check(data[i], 7, 1) &&
                check(data[i], 6, 0) && 
                check(data[i+1], 8, 1) && 
                check(data[i+1], 7, 0) {
                    i+=2
            } else {
                return false 
            }
        } else {
            i += 1 
        } 

    }
    return true 
}