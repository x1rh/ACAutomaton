typedef long long ll;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int j;
        ll ans = 0;
        for(int i=0; i<n; ){
            for(j=i+1; j<n&&prices[j-1]-1==prices[j]; ++j);
            
            ll len = j - i;
            ans += (1+len) * len / 2;
            i = j;
        }
        return ans;
    }
};