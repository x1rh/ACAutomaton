#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        vector<int> ans;

        vector<int> rest;
        set<int> s;
        s.insert(arr2.begin(), arr2.end());

        for(int i=0; i<arr1.size(); ++i){
            auto it = s.find(arr1[i]);
            if(it!=s.end() && *it==arr1[i]){
                ++mp[arr1[i]];
            }
            else{
                rest.push_back(arr1[i]);
            }
        }

        for(int i=0; i<arr2.size(); ++i){
            for(int j=0; j<mp[arr2[i]]; ++j){
                ans.push_back(arr2[i]);
            }
        }

        sort(rest.begin(), rest.end());

        for(int i=0; i<rest.size(); ++i){
            ans.push_back(rest[i]);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr1({2,3,1,3,2,4,6,7,9,2,19});
    vector<int> arr2({2,1,4,3,9,6});
    vector<int> ans = sol.relativeSortArray(arr1, arr2);
    print(ans);
    return 0;
}