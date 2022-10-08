func longestPalindrome(s string) int {
    mp := make(map[rune]int)


    for _, c := range s {
        mp[c] += 1
    }

    one := false 
    ans := 0 

    for _, v := range mp {
        if v % 2 == 1 {
            one = true 
            ans += v - 1
        } else {
            ans += v 
        }
    }

    if one {
        ans += 1
    }

    return ans 
}