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