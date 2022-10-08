func mirrorTree(root *TreeNode) *TreeNode {
    dfs(root)
    return root 
}

func dfs(root *TreeNode) {
    if root != nil {
        if root.Left == nil && root.Right == nil {
            return 
        } else {
            dfs(root.Left)
            dfs(root.Right)
            root.Left, root.Right = root.Right, root.Left
        }        
    }
}