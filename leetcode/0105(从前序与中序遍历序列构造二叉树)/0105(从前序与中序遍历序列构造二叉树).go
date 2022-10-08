func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil 
    }
    return dfs(preorder, 0, len(preorder)-1, inorder, 0, len(inorder)-1) 
}

func dfs(pr []int, pst, ped int, in []int, ist, ied int) *TreeNode {
    if pst == ped || ist == ied{
        return &TreeNode{Val: pr[pst]}
    }

    idx := 0
    for idx=ist; idx<=ied; idx++ {
        if in[idx] == pr[pst] {
            break 
        }
    }

    l := idx-ist 
    r := ied-idx 

    root := &TreeNode{Val: in[idx]}
    
    if l==0 {
        root.Left = nil 
    } else {
        root.Left =  dfs(pr, pst+1, pst+1+l-1, in, ist, idx-1)
    }

    if r==0 {
        root.Right = nil       
    } else {
        root.Right = dfs(pr, pst+1+l, ped, in, idx+1, ied)
    }
    return root 
}