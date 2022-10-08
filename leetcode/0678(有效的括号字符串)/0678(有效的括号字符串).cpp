class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=n; ++j){
                if(s[i-1]=='(' && j-1>=0){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(s[i-1]=='*'){
                    dp[i][j] = dp[i-1][j];
                    if(j-1>=0) dp[i][j] = dp[i][j] | dp[i-1][j-1];
                    if(j+1<=i) dp[i][j] = dp[i][j] | dp[i-1][j+1];
                }
                else if(s[i-1]==')' && j+1<=i){
                    dp[i][j] = dp[i-1][j+1];
                }
            }
        }
        return dp[n][0];
    }
};