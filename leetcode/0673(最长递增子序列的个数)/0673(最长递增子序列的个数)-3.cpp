class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        int maxl = 1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]){
                    if(dp[i].first < dp[j].first+1){
                        dp[i].first = dp[j].first+1;
                        dp[i].second = dp[j].second;
                        maxl = max(maxl, dp[i].first);
                    }
                    else if(dp[i].first == dp[j].first+1){
                        dp[i].second += dp[j].second;
                    }
                }                
            }
        }
        int ans = 0;
        for(auto &[l, c] : dp){
            if(l == maxl){
                ans += c;
            }
        }
        return ans;
    }
};