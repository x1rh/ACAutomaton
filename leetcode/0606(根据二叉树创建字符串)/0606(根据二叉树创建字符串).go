func tree2str(root *TreeNode) string {
    if root != nil {
        ans := fmt.Sprintf("%v", root.Val)
        left := tree2str(root.Left)
        right := tree2str(root.Right)
        if root.Left != nil {
            ans = ans + fmt.Sprintf("(%v)", left)
        } else if root.Right != nil {
            ans = ans + "()"
        }


        if root.Right != nil {
            ans = ans + fmt.Sprintf("(%v)", right)
        }

        return ans 

    } else {
        return ""
    }
}