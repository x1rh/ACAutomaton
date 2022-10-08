class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            auto it = ump.find(target-nums[i]);
            if((it!=ump.end()) && (it->first == (target-nums[i]))){
                return {it->second, i};
            }
            else{
                ump[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
