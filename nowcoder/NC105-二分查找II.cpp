class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        auto idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(idx>=nums.size() || nums[idx]!=target) return -1;
        else return idx;
    }
};