class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto st = unordered_set<string>();
        for(auto &x : wordDict){
            st.insert(x);
        }
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=1; i<=s.size(); ++i){
            for(int j=0; j<i; ++j){
                if(dp[j] && (st.find(s.substr(j, i-j))!=st.end())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};