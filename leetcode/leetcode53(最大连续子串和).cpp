#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    // 最大连续子数组和, 用前缀和加暴力的方法, O(n^2), 看了别人题解发现根本不用前缀和, 石乐志
    int maxSubArray(vector<int>& nums) {
        vector<long long> pre;
        long long sum=0, maxsum=nums.size()==0?0:nums[0];
        for(auto i=0; i<nums.size(); ++i){
            sum += nums[i];
            pre.push_back(sum);
        }
        for(auto i=0; i<nums.size(); ++i){
            for(auto j=i; j<nums.size(); ++j){
                maxsum = max(maxsum, pre[j]-pre[i]+nums[i]);
            }
        }
        return maxsum;
    }
    */

   /*
   // 动态规划法O(n) 定义dp[i]为以i为结尾的最大值,
   // 递推关系为dp[i] = max(dp[i-1]+nums[i], nums[i]), 即只思考子结构[a, b] 求它们的最大子串和, 要么为a+b, 要么为b
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<long long> dp(nums.size());
        long long maxsum = (long long)nums[0];
        dp[0] = nums[0];
        for(auto i=1; i<nums.size(); ++i){
            dp[i] = max(dp[i-1]+nums[i], (long long)nums[i]);
            maxsum = max(dp[i], maxsum);
        }
        return maxsum;
    }
    */

    // 分治法
    // 分治法重点在于处理跨越的那部分, 两遍for循环即可, 复杂度不好目测...O(nlogn)?
    // 即leftsum, cross=cross_le+cross_ri, righsum三者中最大者

    long long dfs(vector<int>& nums, int l, int r){
        if(l==r) return nums[l];

        int mid = (l+r)/2;
        long long leftsum = dfs(nums, l, mid);
        long long righsum = dfs(nums, mid+1, r);

        long long cross_le=numeric_limits<long long>::min();
        long long cross_ri=numeric_limits<long long>::min();
        long long temp_le=0, temp_ri=0;
        for(int i=mid; i>=l; --i){
            temp_le += nums[i];
            cross_le = max(cross_le, temp_le);
        }

        for(int i=mid+1; i<=r; ++i){
            temp_ri += nums[i];
            cross_ri = max(cross_ri, temp_ri);
        }

        long long cross = cross_le + cross_ri;

        return max(max(leftsum, righsum), cross);
    }

    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

};

int main(){
    Solution sol;
    vector<int> v({-2,1,-3,4,-1,2,1,-5,4});
    cout<<sol.maxSubArray(v)<<endl;
    return 0;
}