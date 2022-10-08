# 题目
[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)



# 题意
要求用一个已排序的数组生成一个高度平衡的二叉树

# 思路 
将其构建成二分搜索树必定是高度平衡的

```go
func sortedArrayToBST(nums []int) *TreeNode {
    return dfs(nums, 0, len(nums)-1)
}

func dfs(arr []int, l, r int) *TreeNode {
    if r-l+1 <= 0 {
        return nil 
    } else {
        mid := (l+r)/2
        left := dfs(arr, l, mid-1)
        right := dfs(arr, mid+1, r)

        return &TreeNode{
            Val: arr[mid],
            Left: left,
            Right: right,
        }
    }
}
```
