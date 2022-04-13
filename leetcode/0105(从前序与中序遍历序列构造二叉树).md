# 题目
[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


# 题意
根据前序和中序序列，构建二叉树

# 思路
前序序列第一个节点，将中序序列分为两个部分，以此递归。

```go
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
```