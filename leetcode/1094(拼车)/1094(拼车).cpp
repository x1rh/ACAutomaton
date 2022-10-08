class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        int n = trips.size();
        for(int i=0; i<n; i++) {
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }

        int cnt = 0;
        for(auto &[k, v] : mp) {
            cnt += v;
            if(cnt > capacity) {
                return false ;
            }           
        }
        return true;
    }
};