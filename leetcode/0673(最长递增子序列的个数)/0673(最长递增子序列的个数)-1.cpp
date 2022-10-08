class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<vector<int>> rc(n+1, vector<int>(n, 0));
        int ans = 1;
        for(int i=0; i<n; ++i){
            rc[1][i] = 1;
        }
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j] + 1;
                        rc[dp[i]][i] += rc[dp[i]-1][j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        rc[dp[i]][i] += rc[dp[i]-1][j];
                    }
                    
                }
            }
            ans = max(ans, dp[i]);
        }
        
        int retval = 0;
        for(int i=0; i<n; ++i){
           retval += rc[ans][i];
        }
        return retval;
    }
};