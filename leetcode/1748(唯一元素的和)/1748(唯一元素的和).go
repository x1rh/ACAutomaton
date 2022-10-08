func sumOfUnique(nums []int) int {
    mp := make(map[int]int)
    for _, x := range nums {
        mp[x] += 1
    }

    var ans int = 0
    for k, v := range mp {
        if v == 1 {
            ans += k
        }
    }

    return ans
}