# 题目
[6059. 检查是否有合法括号字符串路径](https://leetcode-cn.com/problems/check-if-there-is-a-valid-parentheses-string-path/)

# 题意
判断从矩形的左上角走到右下角的路径是否合法

# 思路
- dfs
- 注意，括号匹配只包含一种括号，只需要在过程中记录左括号个数，遇到左括号+1，遇到右括号-1，如果左括号数为负数则终止，到最后检查是否为0
- 记忆化搜索：(i,j,c)只访问一次。

```go
func hasValidPath(grid [][]byte) bool {
    m := len(grid)
    n := len(grid[0])
    
    vis := make([][][]bool, m)
    for i:=0; i<m; i++ {
        vis[i] = make([][]bool, n)
        for j:=0; j<n; j++ {
            vis[i][j] = make([]bool, m+n)
        }
    }

    flag := false 
    var dfs func(int, int, int) 
    dfs = func(i, j, c int) {
        if grid[i][j]  == '(' {
            c += 1 
        } else {
            c -= 1 
        }
        if c < 0 {
            return 
        }
        if vis[i][j][c] {
            return 
        }
        vis[i][j][c] = true 
        
        if i==m-1 && j==n-1 {
            if c == 0{
                flag = true 
            }
        }
        if flag {
            return 
        }
        
        if i+1 < m {
            dfs(i+1, j, c)
        }
        if j+1 <n {
            dfs(i, j+1, c)
        }
    }
    dfs(0, 0, 0)
    return flag 
}

```


## python 
python的lru_cache有点无脑了。。。
```python
class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])
    
 
        global flag 
        flag = False 
        @lru_cache(None)
        def dfs(i, j, c):
            global flag 
            if grid[i][j]  == '(':
                c += 1 
            else:
                c -= 1 

            if c < 0:
                return 

            if i==m-1 and j==n-1:
                if c == 0:
                    flag = True

            if flag:
                return 


            if i+1 < m:
                dfs(i+1, j, c)

            if j+1 <n:
                dfs(i, j+1, c)


        dfs(0, 0, 0)
        return flag 

```