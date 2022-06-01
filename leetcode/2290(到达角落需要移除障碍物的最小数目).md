# 题目
[2290. 到达角落需要移除障碍物的最小数目](https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/)


# 题意
从左上角到右下角经过的最少障碍数

# 思路
01-BFS + 堆优化

```cpp
class Solution {
public:
    struct node{
        int x, y, c;
        node(){}
        node(int x, int y, int c):x(x), y(y), c(c) {}
        bool operator<(const node& rhs) const{
            return this->c > rhs.c;
        }
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        vector<vector<int>> vis = vector(m, vector<int>(n, 0x3f3f3f3f));
        
        priority_queue<node> pq;
        vis[0][0] = grid[0][0];
        pq.push(node(0,0,0));
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            if(tp.x == m-1 && tp.y == n-1) {
                break; 
            }
            
            for(int i=0; i<4; i++) {
                int x = dx[i] + tp.x;
                int y = dy[i] + tp.y;
                if(0<=x && x<m && 0<=y && y<n && tp.c + grid[x][y] < vis[x][y] ) {
                    vis[x][y] = tp.c + grid[x][y];
                    pq.push({x, y, vis[x][y]});
                }
            }
            
        }
        return vis[m-1][n-1];
    }
};
```

