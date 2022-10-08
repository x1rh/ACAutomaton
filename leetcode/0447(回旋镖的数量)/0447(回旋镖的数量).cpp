class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
            int n = points.size();
            int ans = 0;
            if(n<=2) return 0;
            for(auto &x : points){
                map<int, int> mp;
                for(auto &y : points){
                    int d = (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
                    ++mp[d];
                }
                for(auto &[_, cnt] : mp){
                    ans += cnt * (cnt-1);
                }            
            }
            return ans;
        }
};