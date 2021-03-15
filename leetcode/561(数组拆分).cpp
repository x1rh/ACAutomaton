#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print(vector<T>& v){
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template<typename T>
void print(vector<vector<T>>& v){
    for(auto iti=v.begin(); iti!=v.end(); ++iti){
        for(auto itj=(*iti).begin(); itj!=(*iti).end(); ++itj){
            cout<<*itj<<" ";
        }
        cout<<endl;
    }
}

class Solution {
public:
    // 1, 4, 3, 2    => 1, 2, 3, 4 => (1, 2)  (3, 4)
    // 1, 1, 2, 3    => (1, 1) (2, 3)
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size() / 2;
        int ans = 0;
        for(int i=0; i<len; ++i){
            ans += nums[i*2];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,4,3,2});
    cout<<sol.arrayPairSum(v)<<endl;
    return 0;
}