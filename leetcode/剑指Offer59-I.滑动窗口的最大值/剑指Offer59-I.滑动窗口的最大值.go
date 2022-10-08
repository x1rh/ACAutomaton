func maxSlidingWindow(nums []int, k int) []int {
    n := len(nums)
    q := []int{}
    ans := []int{}
    for i,j:=0,0; j<n; j++ {
        for len(q)!=0 && q[len(q)-1] < nums[j] {
            q = q[:len(q)-1]
        }
        q = append(q, nums[j])

        for j-i+1 > k {
            if q[0] == nums[i] {
                q = q[1:]
            }
             i += 1 
        }
        if j-i+1 == k {
            ans = append(ans, q[0])
        }
    }

    return ans 
}