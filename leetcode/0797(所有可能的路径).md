# 题目
`https://leetcode-cn.com/problems/all-paths-from-source-to-target/`


# 思路
求从0到n-1的全部路径  

递归+回溯即可


```cpp
class Solution {
public:
    void dfs(
        vector<vector<int>>& graph, 
        vector<int>& pa,
        vector<bool>& vis, 
        vector<vector<int>>& ans,
        int idx,
        int pos
    ){
        if(idx==pa.size()-1){
            ans.emplace_back(pa.begin(), pa.begin()+pos);
        } 
        for(auto &x : graph[idx]){
            if(!vis[x]){
                vis[x] = true;
                pa[pos] = x;
                dfs(graph, pa, vis, ans, x, pos+1);
                vis[x] = false;
            }
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> pa(n, 0);
        vector<bool> vis(n, false);
        vector<vector<int>> ans;
        vis[0] = true;
        pa[0] = 0;
        dfs(graph, pa, vis, ans, 0, 1);
        return ans;
    }
};
```