class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int, int> deg;
        for(auto &x : edges){
            ++deg[x[0]];
            ++deg[x[1]];
        }
        int _max = INT_MIN;
        int ans = -1;
        for(auto &[k, v] : deg) {
            if(v > _max){
                _max = v;
                ans = k;
            }
        }
        return ans;
    }
};