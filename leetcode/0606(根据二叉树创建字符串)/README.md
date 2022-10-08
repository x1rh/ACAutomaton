# 题目
[606. 根据二叉树创建字符串](https://leetcode-cn.com/problems/construct-string-from-binary-tree/)

# 题意

将树的前序遍历加括号后输出，当右子树为空时，不打印括号。


# 思路

```go
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
```
