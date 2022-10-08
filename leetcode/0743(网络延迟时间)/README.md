# 题目
`https://leetcode-cn.com/problems/network-delay-time/`

# 思路
先判断从k出发图的连通性

然后求k到各个点的最短路，取其中最大值


```cpp
class Solution {
public:
    struct Node{
        int to, cost;
        Node(int to, int cost):to(to), cost(cost){}
        bool operator<(const Node &rhs)const{
            return this->cost < rhs.cost;
        }
    };

    void dfs(int st, vector<vector<Node>> &g, map<int, bool> &vis){
        if(!vis[st]){
            vis[st] = true;
            for(auto &el : g[st]){
                dfs(el.to, g, vis);
            }
        }
    }

    int dijkstra(int st, vector<vector<Node>> &g){
        int n = g.size() - 1;
        vector<int> dist(n+1, 0x3f3f3f3f);
        vector<bool> vis(n+1, false);
        dist[st] = 0;

        for(int ii=0; ii<n-1; ++ii){
            int minn = 0x3f3f3f3f;
            int indx = -1;
            for(int j=1; j<=n; ++j){
                if(!vis[j] && dist[j] < minn){
                    minn = dist[j];
                    indx = j;
                }
            }
            vis[indx] = true;
            for(int j=0; j<g[indx].size(); ++j){
                if(dist[indx]+g[indx][j].cost < dist[g[indx][j].to]){
                    dist[g[indx][j].to] = dist[indx]+g[indx][j].cost;
                }
            }
        }

        int ans = -1;
        for(int i=1; i<=n; ++i){
            if(ans < dist[i]) ans = dist[i];
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Node>> g(n+1, vector<Node>());
        for(int i=0; i<times.size(); ++i){
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        map<int, bool> vis;
        dfs(k, g, vis);
        if(vis.size() != n){
            return -1;
        }
        return dijkstra(k, g);
    }
};
```