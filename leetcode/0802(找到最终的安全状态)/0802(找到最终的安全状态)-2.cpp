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