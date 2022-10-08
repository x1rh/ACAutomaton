func reverseOnlyLetters(s string) string {
    var idx []int  

    for i, x := range s {
        if ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z') {
            idx = append(idx, i)
        }
    }

    ans := []byte(s)

    for i, j := 0, len(idx)-1; i < j; i, j = i+1, j-1 {
        ans[idx[i]], ans[idx[j]] = ans[idx[j]], ans[idx[i]]
    }

    return string(ans)
}