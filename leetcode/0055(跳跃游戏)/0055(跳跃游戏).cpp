class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = n-1;
        for(int i=n-2; i>=0; --i){
            if(nums[i]+i+1 >= n) dp[i] = n-1;
            else{
                for(int j=i; j<n && j<=i+nums[i]; ++j){
                    dp[i] = max(dp[j], dp[i]);
                }
            }
        }
        if(dp[0] == n-1) return true;
        else return false;
    } 
};