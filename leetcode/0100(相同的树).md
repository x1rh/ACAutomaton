# 题目
[100. 相同的树](https://leetcode-cn.com/problems/same-tree/)

# 题意
判断两颗二叉树是否相同


# 思路
递归判断即可


```go
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p!=nil && q!=nil {
        if p.Val == q.Val{
            return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
        } else {
            return false 
        }
    } else if p==nil && q==nil {
        return true 
    } else {
        return false 
    }
}
```