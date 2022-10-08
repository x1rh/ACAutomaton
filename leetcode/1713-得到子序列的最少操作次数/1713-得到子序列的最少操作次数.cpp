class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        for(int i=0; i<target.size(); ++i){
            mp[target[i]] = i+1;
        }

        vector<int> vec;
        for(auto &el : arr){
            int idx = mp[el];
            if(idx){
                vec.push_back(idx);
            }
        }

        vector<int> dp;
        if(vec.empty()){
            return target.size();
        }
        dp.push_back(vec[0]);
        for(int i=1; i<vec.size(); ++i){
            if(vec[i] > dp.back()){
                dp.push_back(vec[i]);
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), vec[i]);
                if(it != dp.end()){
                    *it = vec[i];
                }
            }
        }
        return target.size() - dp.size(); 
    }
};