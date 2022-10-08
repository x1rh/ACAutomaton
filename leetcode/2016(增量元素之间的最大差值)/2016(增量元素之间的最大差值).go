func maximumDifference(nums []int) int {
    n := len(nums)
    min := nums[0] 
    ans := -1

    for i:=1; i<n; i++ {
        if nums[i] > min {
            if nums[i] - min > ans {
                ans = nums[i] - min 
            }
        } else {
            min = nums[i]
        }
    }
    return ans 
}