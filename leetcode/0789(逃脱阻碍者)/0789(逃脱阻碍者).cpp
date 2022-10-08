class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> you{0, 0};
        
        auto dist = [](vector<int>& st, vector<int>& ed){
            return abs(st[0] - ed[0]) + abs(st[1] - ed[1]);
        };

        int d = dist(you, target);
        for(auto &x : ghosts){
            if(d>= dist(x, target)){
                return false;
            }
        }
        return true;
    }
};