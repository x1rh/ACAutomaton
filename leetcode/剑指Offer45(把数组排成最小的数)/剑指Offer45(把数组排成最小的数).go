func minNumber(nums []int) string {
    arr := make([]string, len(nums))
    for i:=0; i<len(nums); i++ {
        arr[i] = strconv.Itoa(nums[i])
    }

    sort.Slice(arr, func(i, j int)bool {
        if arr[i]+arr[j] < arr[j]+arr[i] {
            return true 
        } else {
            return false 
        }
    })

    return strings.Join(arr, "")
}