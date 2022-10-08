func missingNumber(nums []int) int {
    var l, r, mid int 

    for l, r=0, len(nums)-1; l<=r; {
        mid = (l+r)/2
        if nums[mid] == mid {
            l = mid + 1 
        } else {
            r = mid - 1 
        }
    }

    return l 
}