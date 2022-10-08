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