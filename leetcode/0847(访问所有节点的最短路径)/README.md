# 题目
`https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/`

# 题意
一口气遍历完无向图的所有点，点和边可以重复访问，求最短路径ans。

# 思路1 状态压缩+BFS
- 注意题目规模 1<=N<=12
- 最短路径ans的值和起点相关联，不同起点有不同的最短路径值。
- 用一个三元组`(i, mask, dist)`进行BFS即可，其中mask为一个bitmap，因为规模小，这里直接用一个int存储
- bfs过程中每个点可以重复入队，做剪枝处理: `unique(i, mask)`， map中(i, mask)的组合唯一
- 初始化时，将每个节点同时放入队列中，dist都为0
- 当mask = target = (1<<n) - 1 时退出bfs
- 不能使用priority_queue，因为mask大的值不代表它访问的点多。

```cpp
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<tuple<int, int, int>> q;
        map<tuple<int, int>, bool> vis;
        for(int i=0; i<graph.size(); ++i){
            q.emplace(i, 1<<i, 0);
            vis[tuple<int, int>(i, 1<<i)] = true;
        }
        int target = (1<<graph.size()) - 1;
        while(!q.empty()){
            auto [idx, mask, dist] = q.front(); q.pop();
            if(mask == target){
                return dist;
            }
            for(auto &x : graph[idx]){
                int x_mask = mask | (1<<x);
                if(!vis[tuple<int, int>(x, x_mask)]){
                    vis[tuple<int, int>(x, x_mask)] = true;
                    q.emplace(x, x_mask, dist+1);
                }
            }
        }
        return 0;

    }
};
```

时间复杂度： O(n^2 * (2*n))  无法理解为什么中件是乘