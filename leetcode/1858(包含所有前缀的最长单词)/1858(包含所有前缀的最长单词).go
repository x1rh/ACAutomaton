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