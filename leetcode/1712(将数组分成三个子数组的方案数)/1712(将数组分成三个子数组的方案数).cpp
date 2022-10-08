typedef long long ll;
const int mod = 1e9+7;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n+1);
        for(int i=1; i<=n; i++) {
            pre[i] = nums[i-1] + pre[i-1];
        }

        int ans = 0;
        for(int i=2; i<n; i++) {
            ll key1 = 2*pre[i]-pre[n];
            ll key2 = pre[i]/2 + 1;
            auto it1 = lower_bound(pre.begin()+1, pre.begin()+i, key1);
            auto it2 = lower_bound(it1, pre.begin()+i, key2);
            ans = (ans + (it2-it1)%mod)%mod;
        }
        return ans;
    }
};