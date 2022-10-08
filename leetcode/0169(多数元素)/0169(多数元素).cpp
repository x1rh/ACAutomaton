class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = -1;
        int cnt = 0;
        for(auto &x : nums){
            if(cnt==0){
                ++cnt;
                can = x;
            }
            else if(x == can){
                ++cnt;
            }
            else{
                --cnt;
            }
        }
        return can;
    }
};