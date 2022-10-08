class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        for(auto &x : nums){
            xo ^= x;
        }

        int idx = -1;

        for(int i=31; i>=0&&(idx==-1); --i){
            if((xo>>i) & 1) idx = i;
        }

        vector<int> ans(2, 0);

        for(auto &x : nums){
            if((x>>idx)&1) {
                ans[0] ^= x;
            }
            else{
                ans[1] ^= x;
            }
        }
        return ans;
    }
};