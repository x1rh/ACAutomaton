func singleNumber(nums []int) int {
    ans := 0 
    for i:=30; i>=0; i-- {
        cnt := 0 
        for j := range nums {
            cnt += (nums[j]>>i) & 1 
        }
        ans <<= 1 
        cnt %= 3 
        ans += cnt 
    }
    return ans 
}