# 题目
[1858. 包含所有前缀的最长单词](https://leetcode-cn.com/problems/longest-word-with-all-prefixes/)

# 题意
从字符串数组中找到一个字符串，要求其所有前缀都在数组中。


# 思路
建字典树，然后对字典树做一次前序遍历，遍历的过程要求遍历到的每个节点都是(字符串的)端点。

```go
type Node struct {
    v byte 
    flag bool
    s string 
    data [26]*Node 
}

type Trie struct {
    root *Node 
}

func (t Trie) insert(x string) {
    cur := t.root 
    for i := range x {
        c := x[i]
        p := cur.data[c-'a']
        if p != nil {
            cur = p 
        } else {
            p = &Node{v:c}
            cur.data[c-'a'] = p 
            cur = p 
        }
    }
    cur.flag = true 
    cur.s = x 
}

func longestWord(words []string) string {
    t := Trie{root: &Node{}}
    for i := range words {
        t.insert(words[i])
    }

    var dfs func(*Node) 
    ans := ""
    dfs = func(root *Node) {
        if root != t.root && !root.flag {
            return 
        }
        for i:=0; i<26; i++ {
            next := root.data[i]
            if next != nil {
                dfs(next)
            }
        }
        
        if len(root.s) > len(ans) || (len(root.s) == len(ans) && root.s < ans) {
            ans = root.s 
        }
    }

    dfs(t.root)
    return ans 
}
```
