func missingElement(nums []int, k int) int {
    for i:=1; i<len(nums); i++ {
        delta := nums[i] - nums[i-1] - 1 
        if delta < k {
            k -= delta 
        } else {
            return nums[i-1] + k
        }
    }

    if k > 0 {
        return nums[len(nums)-1] + k 
    }

    return -1 
}