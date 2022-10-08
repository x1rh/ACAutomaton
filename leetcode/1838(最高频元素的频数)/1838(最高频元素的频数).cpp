class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int l=0;
        long long intervalKSum = 0;
        for(int r=1; r<nums.size(); ++r){
            intervalKSum += (long long) (nums[r]-nums[r-1]) * (r-l);
            while(intervalKSum > k){
                intervalKSum -= (nums[r] - nums[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};