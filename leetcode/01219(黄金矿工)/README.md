# 题目

# 题意
- 一条路走到底（不可以重复走某个点），求路径最大和
- 开头只能是非0点
- 不能走过0点

# 思路
dfs+回溯

cpp版
```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        int ans = 0;
        function<void(vector<vector<int>>& g, int i, int j, int t)> dfs = [&](vector<vector<int>>& g, int i, int j, int t){
            t += g[i][j];
            g[i][j] = 0;
            for(int ii=0; ii<4; ++ii){
                int x = dx[ii] + i;
                int y = dy[ii] + j;
                if(0<=x&&x<m && 0<=y&&y<n && g[x][y]!=0){
                    dfs(g, x, y, t);
                }
            }
            ans = max(ans, t);
            g[i][j] = grid[i][j];
        };

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] != 0){
                    auto g = grid;
                    dfs(g, i, j, 0);
                }
            }
        }
        return ans;
    }
};
```


go版
```go
func getMaximumGold(grid [][]int) int {
    var dx = []int{0, 0, -1, 1}
    var dy = []int{-1, 1, 0, 0}

    ans := 0
    m := len(grid)
    n := len(grid[0])

    var dfs func(g [][]int, i, j, t int)
    dfs = func(g [][]int, i, j, t int){
        t += g[i][j];
        g[i][j] = 0;
        if ans < t {
            ans = t
        }
        for ii:=0; ii<4; ii++{
            x := dx[ii] + i;
            y := dy[ii] + j;
            if(0<=x&&x<m && 0<=y&&y<n && g[x][y]!=0){
                dfs(g, x, y, t);
            }
        }
        g[i][j] = grid[i][j];
    }

    g := make([][]int, m)
    for k:=0; k<m; k++ {
        g[k] = make([]int, n)
    }
    

    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {
            if grid[i][j] != 0 {

                for k:=0; k<m; k++ {
                    copy(g[k], grid[k]);
                }
                dfs(g, i, j, 0)
            }
        }
    }

    return ans;
}
```