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