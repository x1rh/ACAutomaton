func binaryGap(n int) int {  
    b := []int{}
    for n > 0 {
        b = append(b, n%2)
        n /= 2
    }

    ans := 0
    n = len(b)
    for i,j:=0,0; j<n; j++{
        for i<n && b[i] != 1 {
            i++
        }
        if i>=n || b[i] !=1 {
            break 
        }

        j = i+1 
        for j<n && b[j] != 1 {
            j++
        }
        if j>=n || b[j] != 1 {
            break 
        }

        ans = max(ans, j-i)
        i = j 
    }
    return ans 
}

func max(x, y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
}