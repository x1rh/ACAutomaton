func get(x []byte) (int64, int64) {
    i := 0
    if x[0] == '-' {
        i = 1
    }
    for ;'0'<=x[i] && x[i] <= '9'; i++ {}
    one, _ := strconv.ParseInt(string(x[0:i]), 10, 32)
    two, _ := strconv.ParseInt(string(x[i+1:len(x)-1]), 10, 32)
    
    return one, two
}

func complexNumberMultiply(num1 string, num2 string) string {
    a, b := get([]byte(num1))
    c, d := get([]byte(num2))

    ans1 := a*c - b*d 
    ans2 :=  a*d + b*c 

    return fmt.Sprintf("%d+%di", ans1, ans2)
}