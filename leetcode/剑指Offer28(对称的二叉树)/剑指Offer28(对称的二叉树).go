func isSymmetric(root *TreeNode) bool {
    if root != nil {
        return dfs(root.Left, root.Right)
    } else {
        return true 
    }
}


func  dfs(l, r *TreeNode) bool {
    if l != nil && r != nil {
        if l.Val == r.Val {
            return dfs(l.Left, r.Right) && dfs(l.Right, r.Left)
        } else {
            return false 
        } 
    } else if l == nil && r == nil {
        return true 
    } else {
        return false 
    }
}