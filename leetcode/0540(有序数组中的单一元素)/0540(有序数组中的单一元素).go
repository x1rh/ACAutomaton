func singleNonDuplicate(nums []int) int {
    l := 0
    r := len(nums) - 1
    for ; l<=r; {
        mid := (l+r)/2
        if ((mid-1>=0)&&(mid%2!=0)&&(nums[mid-1]==nums[mid])) || ((mid+1<len(nums))&&(mid%2==0)&&(nums[mid]==nums[mid+1])) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return nums[l];
}