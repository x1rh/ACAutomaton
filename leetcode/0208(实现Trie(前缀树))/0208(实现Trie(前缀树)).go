type Node struct {
    v byte 
    flag bool     
    data map[byte]*Node 
}

type Trie struct {
    root *Node 
}


func Constructor() Trie {
    return Trie{root: &Node{data: make(map[byte]*Node)}}
}


func (this *Trie) Insert(word string)  {
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


func (this *Trie) Search(word string) bool {
    cur := this.root
    for i := range word {
        v, ok := cur.data[word[i]]; if ok {
            cur = v 
        } else {
            return false 
        }
    }
    return cur.flag
}


func (this *Trie) StartsWith(prefix string) bool {
    cur := this.root 
    for i := range prefix {
        v, ok := cur.data[prefix[i]]; if ok {
            cur = v 
        } else {
            return false 
        }
    }
    return true 
}
