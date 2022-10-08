func stringShift(s string, shift [][]int) string {

    str := []byte(s)

    for i := range shift {
        step := shift[i][1] % len(s)
        if step==0{
            continue 
        }

        if shift[i][0] == 0 {
           str = append(str, str[0:step]...)
           str = str[step:len(str)] 
        } else {
            pre := str[len(str)-step:len(str)]
            str = str[0:len(str)-step]
            str = append(pre, str...)
        }
    }

    return string(str)
}