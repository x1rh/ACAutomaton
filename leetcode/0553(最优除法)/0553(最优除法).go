func optimalDivision(nums []int) string {
    if len(nums) == 1 {
        return strconv.Itoa(nums[0])
    } else if len(nums) == 2 {
        return fmt.Sprintf("%d/%d", nums[0], nums[1])
    } else {
        sa := make([]string, len(nums)-1)
        for i := range sa {
            sa[i] = strconv.Itoa(nums[i+1])
        }
        return strconv.Itoa(nums[0]) + "/" + "(" + strings.Join(sa, "/") + ")"
    }
}