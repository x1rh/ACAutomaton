class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        for(int i=1; i<nums.size()-1; ++i){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return i;
            }
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[0]<nums[1]) {
            if(nums.size()==2) return 1;
            if(nums.size()>2 && nums[1]> nums[2]) return 1; 
        }
        if(nums[nums.size()-2] < nums.back()) return nums.size()-1;
        return -1;
    }
};