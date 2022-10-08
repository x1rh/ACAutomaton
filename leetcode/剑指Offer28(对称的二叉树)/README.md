# 题目
[剑指 Offer 28. 对称的二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)

# 题意
判断一棵二叉树是否和其镜像相等


# 思路
逐层向下递归左右子树节点，判是否相等。


```go
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
```