# 题目
[1469. 寻找所有的独生节点](https://leetcode-cn.com/problems/find-all-the-lonely-nodes/)


# 题意
求二叉树的独生节点，独生节点x指的是父节点只有x这一个子节点

# 思路
```go
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
```

