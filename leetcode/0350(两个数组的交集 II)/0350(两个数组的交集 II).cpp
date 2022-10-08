class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2, mp3;
        for(auto &x : nums1){
            mp1[x] += 1;
            if(!mp3[x]) {
                mp3[x] = 1;
            }
        }
        for(auto &x : nums2){
            mp2[x] += 1;
            if(mp3[x]==1){
                mp3[x] = 2;
            } 
        }
        vector<int> ans;
        for(auto &[k, v] : mp3){
            if(v==2){
                int lp = min(mp1[k], mp2[k]);
                for(int i=0; i<lp; ++i){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};