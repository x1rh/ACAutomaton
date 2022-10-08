func numSubarrayProductLessThanK(nums []int, k int) int {
    if k == 0 {
        return 0 
    }
    n := len(nums) 
    ans := 0 
    pre := 1
    for i,j:=0,0; j<n; j++{
        pre *= nums[j]  
        for ; i<=j && pre >= k; i++ {
            pre /= nums[i] 
        }
        ans += j-i + 1 
    }
    return ans 
}