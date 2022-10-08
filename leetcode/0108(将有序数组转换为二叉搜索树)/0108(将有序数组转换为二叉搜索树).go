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