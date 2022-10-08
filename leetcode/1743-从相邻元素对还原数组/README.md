# 链接
`https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/`

# 思路
将数组构造成无向图，然后dfs，利用第一个数组元素和最后一个数组元素度为1这一点进行剪枝

噗呲，这暴搜能过，有点玄学


```cpp
class Solution {
public:
    void dfs(int curr, map<int, vector<int>> &g, vector<int> &ans, int &idx, map<int, bool> &vis){
        if(idx == ans.size()) return;
        vis[curr] = true;
        ans[idx++] = curr;
        for(auto &el : g[curr]){
            if(!vis[el]){
                dfs(el, g, ans, idx, vis);
                vis[el] = false;
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> g;
        map<int, int> deg;
        for(auto &each : adjacentPairs){
            g[each[0]].push_back(each[1]);
            g[each[1]].push_back(each[0]);
            ++deg[each[0]];
            ++deg[each[1]];
        }

        vector<int> candidate;

        for(auto &it : deg){
            if(it.second == 1){
                candidate.push_back(it.first);
            }
        }

        for(auto &el : candidate){
            map<int, bool> vis;
            vector<int> ans(adjacentPairs.size()+1, 0);
            int idx = 0;
            dfs(el, g, ans, idx, vis);
            if(idx == ans.size()){
                return ans;
            }
        }
        return vector<int> (1, 0);
    }
};
```


# 官方题解
结论：
确定开头和结尾，就唯一确定了结果

判断左右：
由于存的时候类似于存无向图，所以得判断左右。这点其实很好解决，例如（A, X, B），
此时如果遍历到X，如果边edge(X, Y)， 其中Y只能为A和B，拿Y去和其数组中左边的值相比即可。

```cpp
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for (auto& adjacentPair : adjacentPairs) {
            mp[adjacentPair[0]].push_back(adjacentPair[1]);
            mp[adjacentPair[1]].push_back(adjacentPair[0]);
        }

        int n = adjacentPairs.size() + 1;
        vector<int> ret(n);
        for (auto& [e, adj] : mp) {
            if (adj.size() == 1) {
                ret[0] = e;
                break;
            }
        }

        ret[1] = mp[ret[0]][0];
        for (int i = 2; i < n; i++) {
            auto& adj = mp[ret[i - 1]];
            ret[i] = ret[i - 2] == adj[0] ? adj[1] : adj[0];
        }
        return ret;
    }
};
```