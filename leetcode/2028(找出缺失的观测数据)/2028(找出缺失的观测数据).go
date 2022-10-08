func missingRolls(rolls []int, mean int, n int) []int {
    m := len(rolls)
    ans := make([]int, n)
    sum := 0 
    for i := range rolls {
        sum += rolls[i] 
    }

    cnt := (n+m)*mean - sum 

    if cnt < n || cnt>6*n {
        return []int{}
    }

    x, y := cnt/n, cnt%n 

    for i := range ans {
        ans[i] = x 
        if i < y {
            ans[i] += 1 
        }
    }
    return ans 
}