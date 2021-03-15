#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return max(nums[0]*nums[1]*nums[len-1], nums[len-1]*nums[len-2]*nums[len-3]);
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3, 4});
    cout<<sol.maximumProduct(v)<<endl;

    return 0;
}