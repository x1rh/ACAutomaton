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