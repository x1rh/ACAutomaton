class Solution {
public:
    int findMin(vector<int>& nums) {
        int mx = 0x3f3f3f3f;
        for(auto &x : nums){
            if(x < mx){
                mx = x;
            }
        }
        return mx;
    }
};