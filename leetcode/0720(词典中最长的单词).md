# 题目
[720. 词典中最长的单词](https://leetcode-cn.com/problems/longest-word-in-dictionary/)

# 题意
给一个字符串数组，求其中最长的一个单词，这个单词满足：这个单词的所有前缀能在数组中找到，例如：`a, ab, abc, abcd`。
则答案是abcd。长度相同时返回字典序最小的。



# 思路
我也看不懂我当时的思路是什么？哈哈哈哈

```go
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
```