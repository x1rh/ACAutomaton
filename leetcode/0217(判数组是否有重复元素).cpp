#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print(const vector<T>& v){
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
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        if(it == nums.end()) return false;
        else return true;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,2,3,4,5, 6, 7, 7, 8, 9});
    cout<<sol.containsDuplicate(v)<<endl;
    return 0;
}