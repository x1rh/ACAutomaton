# 题目
[543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/submissions/)

# 题意
求二叉树的直径

# 思路1： dfs
话说为什么我被教的做法是先求离根的最远点，再求从这点出发的最远点。    
这个方法看起来非常正确，效率也很好啊？  

```go
func diameterOfBinaryTree(root *TreeNode) int {
    ans := 0 

    var dfs func(*TreeNode) int 
    dfs = func(rt *TreeNode) int {
        if rt != nil {
            l := dfs(rt.Left)
            r := dfs(rt.Right)

            if l+r > ans {
                ans = l+r
            }
            return max(l, r) + 1  
        } else {
            return 0 
        }
    }

    dfs(root)
    return ans 
}

func max(x, y int) int {
    if x > y {
        return x 
    } else {
        return y 
    }
}
```

# 思路2：两次dfs
```go
func diameterOfBinaryTree(root *TreeNode) int {

    g := make(map[*TreeNode][]*TreeNode)

    var build func(*TreeNode)
    build = func(rt *TreeNode) {
        if rt != nil {
            if rt.Left != nil {
                g[rt] = append(g[rt], rt.Left)
                g[rt.Left] = append(g[rt.Left], rt)
            }
            if rt.Right != nil {
                g[rt] = append(g[rt], rt.Right)
                g[rt.Right] = append(g[rt.Right], rt)
            }
            build(rt.Left)
            build(rt.Right)
        }
    }

    var dfs1 func(*TreeNode)(int, *TreeNode) 
    dfs1 = func(rt *TreeNode) (int, *TreeNode) {
        if rt != nil {
            if rt.Left == nil && rt.Right == nil {
                return 1, rt 
            }

            h1, p1 := dfs1(rt.Left)
            h2, p2 := dfs1(rt.Right)
            if h1 > h2 {
                return h1+1, p1 
            } else {
                return h2+1, p2 
            }
        } else {
            return 0, nil 
        }
    }

    ans := 0 
    vis := make(map[*TreeNode]bool)
    var dfs2 func(*TreeNode, int) 
    dfs2 = func(rt *TreeNode, l int) {
        if l > ans {
            ans = l 
        }
        if rt != nil {
            for _, v := range g[rt] {
                if !vis[v] {
                    vis[v] = true 
                    dfs2(v, l+1)
                    vis[v] = false 
                }
            }
        }
    }

    build(root)
    _, p := dfs1(root)
    vis[p] = true 
    dfs2(p, 0)

    return ans 
}
```