#include <iostream>
#include <vector>
#include <algorithm>
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
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        if(k<0) return 0;
        if(k==0){
            map<int, int> mp;
            for(int i=0; i<nums.size(); ++i){
                mp[nums[i]] += 1;
            }
            for(auto it=mp.begin(); it!=mp.end(); ++it){
                if(it->second >= 2) ++cnt;
            }
            return cnt;
        }
        else{
            sort(nums.begin(), nums.end());
            auto ed = unique(nums.begin(), nums.end());
            for(auto it=nums.begin(); it!=ed; ++it){
                auto idx = lower_bound(it+1, ed, (*it)+k);
                if(idx!=ed && (*idx)==(*it)+k){
                    ++cnt;
                    // cout<<*it<<" "<<*idx<<endl;
                }
            }
            return cnt;
        }
    }
};

int main(){
    Solution sol;
    // 6,2,9,3,9,6,7,7,6,4
    vector<int> v({6,2,9,3,9,6,7,7,6,4});
    cout<<sol.findPairs(v, 3)<<endl;
    // sort(v.begin(), v.end());
    // print(v);
    // auto it = unique(v.begin(), v.end());
    // print(v);
    // cout<<*(it-2)<<endl;
    return 0;
}