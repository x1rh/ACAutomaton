class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return 0;
        int ans = 0;
        for(int i=0; i<nums.size()-2; ++i){
            for(int j=i+1; j<nums.size()-1; ++j){
                auto idx = lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j]);
                idx--;
                if(*idx<nums[i]+nums[j]){
                    int tmp = (idx - nums.begin() -j - 1 + 1);
                    if(tmp > 0){
                        ans += tmp;
                    }
                }
            }
        }
        return ans;
    }
};