func isSubStructure(Aa *TreeNode, Bb *TreeNode) bool {
    if Aa==nil || Bb==nil {
        return false 
    }

    var dfs func(*TreeNode, *TreeNode) bool

    dfs = func(A *TreeNode, B *TreeNode) bool {
        if B==nil {
            return true 
        } 
        if A==nil {
            return false 
        }

        if A.Val == B.Val {
            return dfs(A.Left, B.Left) && dfs(A.Right, B.Right)
        } else {
            return false 
        }
    }


    var dfs2 func(*TreeNode ) 
    cond := false 
    dfs2 = func(A *TreeNode)  {
        if cond || A == nil {
            return 
        }
        if A.Val == Bb.Val {
            if dfs(A, Bb) {
                cond = true 
            } 
        } 
        dfs2(A.Left)
        dfs2(A.Right) 
    }

    dfs2(Aa)

    return cond 
}