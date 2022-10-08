class Solution {
public:
    static bool cmp(const pair<int, int> pii, int key){
        return pii.first < key;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; ++i){
            v[i].first = nums[i];
            v[i].second = i;
        }


        sort(v.begin(), v.end());

        for(int i=0; i<n-1; ++i){
            auto it = lower_bound(v.begin()+i+1, v.end(), target-v[i].first, cmp);
            if( (it!=v.end()) && (it->first == (target-v[i].first))) {
                return {v[i].second, it->second};
            }

        }
        return {-1, -1};
    }
};
