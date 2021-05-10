#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 利用lower_bound与distance可以直接写出
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return distance(nums.begin(), it);
    }
};

int main(){
    Solution sol;
    vector<int> v({1,3,5,6});
    cout<<sol.searchInsert(v, 0)<<endl;
    return 0;
}