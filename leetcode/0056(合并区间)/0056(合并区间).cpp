class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<tuple<int, int>> vec;
        vector<vector<int>> ans;
        for(auto &x : intervals){
            int l = x[0];
            int r = x[1];
            vec.emplace_back(l ,r);
        }
        sort(vec.begin(), vec.end());
        for(auto &x : vec){
            auto [l, r] = x;
            if(ans.size()==0){
                ans.push_back({l, r});
            }
            else{
                if(l>ans.back()[1]){
                    ans.push_back({l, r});
                }
                else{
                    if(r > ans.back()[1]){
                        ans.back()[1] = r;
                    }
                }
            }
        }
        return ans;
    }
};