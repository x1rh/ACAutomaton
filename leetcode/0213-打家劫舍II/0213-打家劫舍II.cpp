class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> f(n+2);
        if(n == 1) {
            return nums[0];
        } else if(n == 2) {
            return max(nums[0], nums[1]);
        }

        f[0] = f[1] = 0;
        for(int i=0; i<n-1; i++) {
            f[i+2] = max(f[i+1], f[i] + nums[i]);
            if(f[i+2] > ans) {
                ans = f[i+2];
            }
        }   
        f[0] = f[1] = f[2] = 0;
        for(int i=1; i<n; i++) {
            f[i+2] = max(f[i+1], f[i] + nums[i]);
            if(f[i+2] > ans) {
                ans = f[i+2];
            }
        }
        return ans; 
    }

};