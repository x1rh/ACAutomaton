func twoSum(numbers []int, target int) []int {
    for i, x := range numbers {
        l := i+1
        r := len(numbers)-1
        tar := target - x
        for ; l<=r; {
            mid := l + (r-l)>>1
             
            if numbers[mid] == tar {
                return []int{i+1, mid+1}
            } else if tar > numbers[mid]{
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }
    return []int{}
}