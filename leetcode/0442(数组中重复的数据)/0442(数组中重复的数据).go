func findDuplicates(nums []int) []int {
    n := len(nums)
    for i:=0; i<n; i++ {
        for nums[i] != nums[nums[i]-1] {
            nums[i], nums[nums[i]-1]  = nums[nums[i]-1], nums[i] 
        }
    }

    ans := []int{}
    for i:=0; i<n; i++ {
        if i != nums[i] - 1 {
            ans = append(ans, nums[i])
        }
    }
    return ans 
}