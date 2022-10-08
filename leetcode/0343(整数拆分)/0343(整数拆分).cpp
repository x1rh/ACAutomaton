class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; ++i){
            int tmp = 0;
            for(int j=1; j<i; ++j){
                tmp = max(tmp, max(dp[j]*(i-j), j*(i-j)));
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};