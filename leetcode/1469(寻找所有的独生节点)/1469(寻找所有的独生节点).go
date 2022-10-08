func getLonelyNodes(root *TreeNode) []int {
    ans := make([]int, 0)

    var dfs func(*TreeNode, *TreeNode) 

    dfs = func(rt, fa *TreeNode) {
        if rt != nil {
            if rt != root {
                if (rt == fa.Left && fa.Right == nil) || (rt == fa.Right && fa.Left == nil) {
                    ans = append(ans, rt.Val)
                }  
            }
            

            dfs(rt.Left, rt)
            dfs(rt.Right, rt)
        }
    }

    dfs(root, nil)

    return ans 
}