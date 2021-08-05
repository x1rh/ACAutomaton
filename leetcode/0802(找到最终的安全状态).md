# 题目
`https://leetcode-cn.com/problems/find-eventual-safe-states/`


# 思路
## dfs + 三色标记法

明确题目求解内容为：从x点出发，能否到达其某个终点，在次过程中没有环

A: 在dfs时，点的访问存在先后顺序，先访问的点是否满足条件（成为一个解），依赖于在其之后所访问的点是否满足条件，如果之后的点不满足条件，则x点不满足条件。

我们对dfs时栈里的点染色为1，如果dfs过程中遇到为1的点，就可以认为所有栈中的点都不满足条件，逐层return false。

如果dfs过程中全部满足条件，则将点染色为2.


```cpp
class Solution {
public:
    bool dfs(int st, vector<vector<int>> &graph, vector<int> &color){
        if(color[st]>0){
            return color[st] == 2;
        }

        color[st] = 1;
        for(auto x : graph[st]){
            if(!dfs(x, graph, color)) return false;
        }
        color[st] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> color(graph.size());
        for(int i=0; i<graph.size(); ++i){
            if(dfs(i, graph, color)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```


## 反图 + 拓扑排序
由于先访问的点，依赖于后访问的点，若一个点出度为0，则是安全的。反过来，我们得到一个反图，将入度为0的点加入队列，删除这个点（这个点是安全的），将这个点的出边指向的点的入度全部减1，将入度为0的点入队，则最后剩下的入度不为0的点就是不安全的点。

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rg(graph.size());
        vector<int> deg(graph.size());
        for(int i=0; i<graph.size(); ++i){
            for(int j=0; j<graph[i].size(); ++j){
                rg[graph[i][j]].push_back(i);
            }
            deg[i] = graph[i].size();  //反图的入度等于原图的出度
        }

        queue<int> q;
        for(int i=0; i<graph.size(); ++i){
            if(deg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int fr = q.front(); q.pop();
            for(auto &x : rg[fr]){
                --deg[x];
                if(deg[x] == 0) q.push(x);
            }
        }

        vector<int> ans;
        for(int i=0; i<graph.size(); ++i){
            if(deg[i] == 0) ans.push_back(i);
        }
        return ans;

    }
};
```


## 我的一个T了的代码
我是按照求环来做的，而不是按照判断dfs是否能遇到环来做的。显然不够正确，针对性不够

```cpp
class Solution {
public:
    void dfs(int st, vector<vector<int>>& graph, map<int, bool> &circle, map<int, bool> &vis){
        vis[st] = true;
        for(int i=0; i<graph[st].size(); ++i){
            if(!vis[graph[st][i]] && !circle[graph[st][i]]){
                dfs(graph[st][i], graph, circle, vis);
                vis[graph[st][i]] = false;
            }
            else{
                for(auto &[k, v] : vis){
                    if(v){
                        circle[k] = true;
                    }
                }
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        map<int, bool> circle;
        vector<int> ans;
        for(int i=0; i<graph.size(); ++i){
            map<int, bool> vis;
            if(!circle[i]){
                dfs(i, graph, circle, vis);
            }
            if(!circle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

