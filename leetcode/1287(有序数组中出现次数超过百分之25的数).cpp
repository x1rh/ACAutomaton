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
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> mp;
        int temp;
        for(int i=0; i<arr.size(); ++i){
            temp = ++mp[arr[i]];
            if(temp > arr.size()*0.25){
                return arr[i];
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,2,6,6,6,6,7,10});
    cout<<sol.findSpecialInteger(v)<<endl;
    return 0;
}