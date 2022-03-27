# 题目
[剑指 Offer 27. 二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)


# 思路
递归交换左右子树

```go
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
```

