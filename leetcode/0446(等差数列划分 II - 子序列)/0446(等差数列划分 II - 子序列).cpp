class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        typedef long long ll;
        vector<map<ll, int>> dp(n, map<ll, int>());
        int ans = 0;
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                ll d = 1L * nums[i] - nums[j];
                int val = dp[j][d];
                dp[i][d] += val + 1;
                ans += val;
            }
        }
        return ans;
    }
};