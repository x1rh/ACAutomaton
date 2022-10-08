#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

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
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i*2<nums.size(); ++i){
            for(int j=0; j<nums[i*2]; ++j){
                res.push_back(nums[i*2+1]);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    return 0;
}