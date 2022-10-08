func longestWord(words []string) string {
    sort.Slice(words, func(i, j int) bool {
        return words[i] < words[j]
    })

    n := len(words)
    max := 0
    ans := ""
    mp := make(map[string]bool)
    mp[""] = true 

    for i, j := 0, 1; i<n-1; j = i+1{
        if len(words[i]) == 1 {
            mp[words[i]] = true 
        }

        for ; j<n; j++ {
            pre := []byte(words[j])
            pre = pre[:len(pre)-1]
            prestr := string(pre)
            
            v, ok := mp[prestr]; if v && ok {
                mp[words[j]] = true 
                continue 
            } else {
                break 
            }
        }
        i = j 
    }

    for i := range words {
        v, ok := mp[words[i]]; if ok && v {
            if len(words[i]) > max {
                max = len(words[i])
                ans = words[i] 
            }
        }
        
    }
    return ans 
}