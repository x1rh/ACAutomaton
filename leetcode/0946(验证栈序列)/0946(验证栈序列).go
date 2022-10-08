func validateStackSequences(pushed []int, popped []int) bool {
    s := []int{}


    for i := range pushed {
        s = append(s, pushed[i])

        for len(s)!=0 && (popped[0] == s[len(s)-1]) {
            popped = popped[1:]
            s = s[:len(s)-1]
        }
    }

    if len(popped) == 0 && len(s) == 0{
        return true 
    } else {
        return false 
    }
}