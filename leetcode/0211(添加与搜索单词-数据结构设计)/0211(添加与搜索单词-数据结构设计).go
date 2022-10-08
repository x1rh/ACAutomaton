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

