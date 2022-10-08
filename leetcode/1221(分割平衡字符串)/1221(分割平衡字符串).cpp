class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        if(n==1) return 0;
        vector<int> prel(n+1, 0);
        vector<int> prer(n+1, 0);
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int cnt_l = 0;
        int cnt_r = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='L') ++cnt_l;
            else ++cnt_r;
            prel[i+1] = cnt_l;
            prer[i+1] = cnt_r;
        }
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){   
                int ll = prel[j+1];
                int lr = prer[j+1];
                int rl = prel[i+1]-prel[j+1];
                int rr = prer[i+1]-prer[j+1];
                if(ll==lr && rl==rr){
                    dp[0][j] = max(dp[0][j], ll==lr?1:0);
                    dp[j+1][i] = max(dp[j+1][i], rl==rr?1:0);
                    dp[0][i] = max(dp[0][i], dp[0][j]+dp[j+1][i]);
                    dp[0][i] = max(dp[0][i], prel[i+1]==prer[i+1]?1:0);
                }
            }
        }
        return dp[0][n-1]==0?1:dp[0][n-1];
    }
};