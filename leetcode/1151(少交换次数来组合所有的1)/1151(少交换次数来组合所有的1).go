func minSwaps(data []int) int {
    n := len(data)
    one := 0 
    for i := range data {
        if data[i] == 1 {
            one += 1 
        }
    }
    if one == 0 {
        return 0 
    }

    ans := 0x3f3f3f3f
    cnt := 0
    for i, j:=0, 0; j<n; j++{
        if data[j] == 0 {
            cnt += 1 
        } 

        for j-i+1 > one {
            if data[i] == 0 {
                cnt -= 1 
            }
            i += 1 
        }

        if j-i+1 == one && cnt < ans {
            ans = cnt 
        }
    }
    return ans 
}