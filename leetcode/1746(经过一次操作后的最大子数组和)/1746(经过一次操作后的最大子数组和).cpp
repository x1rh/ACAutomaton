class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size(), ans;
        vector<vector<int>> f(n, vector<int>(2, 0));
        f[0][0] = nums[0];
        ans = f[0][1] = nums[0] * nums[0];
        for(int i=1; i<n; i++) {
            f[i][0] = max(f[i-1][0] + nums[i], nums[i]);
            f[i][1] = max(max(f[i-1][1] + nums[i], f[i-1][0] + nums[i] * nums[i]), nums[i] * nums[i]);
            ans = max(ans, max(f[i][0], f[i][1]));
        }
        return ans;
    }
};