func twoSum(nums []int, target int) []int {
    mp := map[int]int{}

    for i, x := range nums {
        v, ok := mp[target-x]
        if ok {
            return []int{v, i}
        } else {
            mp[x] = i
        }
    }

    return []int{-1, -1}
}