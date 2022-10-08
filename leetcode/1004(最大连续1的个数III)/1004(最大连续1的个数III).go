func longestOnes(nums []int, kk int) int {
    n := len(nums)
    cnt := 0
    max := 0 

    for l, r:=0, 0; r<n; r++ {
        if nums[r] == 0 {
            if cnt < kk {
                cnt += 1
            } else if cnt > 1{
                for ; l<=r; l++ {
                    if nums[l] == 0 {
                        l += 1 
                        break 
                    }
                }
            } else {
                l = r+1
            }
        }

        if r-l+1 > max {
            max = r-l+1 
        }    
    }

    return max 
}