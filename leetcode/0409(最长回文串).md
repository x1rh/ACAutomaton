# 题目
[409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/)

# 题意
用一个字符串的字符构造一个最长的回文串


# 思路
模拟构建一个回文串即可

```go
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
```