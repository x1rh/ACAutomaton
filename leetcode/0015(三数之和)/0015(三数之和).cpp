class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        map<tuple<int, int, int>, bool> mp;
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                auto it = lower_bound(nums.begin()+j+1, nums.end(), -(nums[i]+nums[j]));
                if(it!=nums.end() && *it==-(nums[i]+nums[j])){
                    tuple<int, int, int> tp = {nums[i], nums[j], *it};
                    if(mp.find(tp)!=mp.end()) continue;
                    mp[tp] = true; 
                    ans.emplace_back(vector<int>({nums[i], nums[j], *it}));
                }
            }
        }
        return ans;
    }
};