# 题目
[211. 添加与搜索单词 - 数据结构设计](https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/)

# 题意
字典树插入，以及含有`.`匹配符的字符串的匹配。

# 思路
字典树+dfs

```go
type Node struct {
    v byte 
    flag bool
    data map[byte]*Node
}

type WordDictionary struct {
    root *Node 
}


func Constructor() WordDictionary {
    return WordDictionary{root: &Node{data:make(map[byte]*Node)}}
}


func (this *WordDictionary) AddWord(word string)  {
    cur := this.root
    for i := range word {
        v, ok := cur.data[word[i]]; if ok {
            cur = v 
        } else {
            n := &Node{v: word[i], data: make(map[byte]*Node)}
            cur.data[word[i]] = n 
            cur = n 
        }
    }
    cur.flag = true 
}


func dfs(root *Node, s string) bool {
    for i := range s {
        if s[i] == '.' {
            for _, v := range root.data {
                if dfs(v, s[i+1:]) {
                    return true 
                }
            }
            return false 
        } else {
            v, ok := root.data[s[i]]; if ok {
                root = v 
            } else {
                return false 
            }
        }
    }
    return root.flag 
}


func (this *WordDictionary) Search(word string) bool {
    return dfs(this.root, word)
}


```



```go
type Node struct {
    v byte 
    flag bool
    data map[byte]*Node
}

type WordDictionary struct {
    root *Node 
}


func Constructor() WordDictionary {
    return WordDictionary{root: &Node{data:make(map[byte]*Node)}}
}


func (this *WordDictionary) AddWord(word string)  {
    cur := this.root
    for i := range word {
        v, ok := cur.data[word[i]]; if ok {
            cur = v 
        } else {
            n := &Node{v: word[i], data: make(map[byte]*Node)}
            cur.data[word[i]] = n 
            cur = n 
        }
    }
    cur.flag = true 
}


func dfs(root *Node, s string, idx int) bool {
    if s[idx] == '.' {
        for _, v := range root.data {
            if idx == len(s) - 1 {
                if v.flag {
                    return true 
                }
            } else if dfs(v, s, idx+1) {
                return true 
            }
        }
        return false 
    } else {
        v, ok := root.data[s[idx]]; if ok {
            if idx == len(s) - 1 {
                return v.flag 
            } else {
                return dfs(v, s, idx+1)
            }
        } else {
            return false 
        }
    }
}


func (this *WordDictionary) Search(word string) bool {
    return dfs(this.root, word, 0)
}

```