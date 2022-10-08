class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        auto jt = upper_bound(nums.begin(), nums.end(), target);
        if(it==nums.end() || *it!=target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else{
            ans.push_back(it-nums.begin());
            ans.push_back(jt-1-nums.begin());
            return ans;
        }
    }
};