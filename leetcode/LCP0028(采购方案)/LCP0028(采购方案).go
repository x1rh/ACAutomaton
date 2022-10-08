func purchasePlans(nums []int, target int) int {
    sort.Ints(nums)

    n := len(nums)

    ans := 0 

    for i := range nums {
        l := i + 1
        r := n - 1 
        for ; l<=r; {
            mid := (l+r)/2

            if nums[mid] + nums[i] <= target {
                l = mid + 1
            } else {
                r = mid - 1 
            }
        }

        ans = (ans + r - i ) % 1000000007
    }

    return ans 
}
