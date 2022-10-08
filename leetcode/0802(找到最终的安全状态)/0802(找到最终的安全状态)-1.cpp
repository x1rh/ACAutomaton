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