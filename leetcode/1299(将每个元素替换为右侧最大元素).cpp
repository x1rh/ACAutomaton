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
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> suf(arr.size(), -1);
        for(int i=arr.size()-2; i>=0; --i){
            suf[i] = max(arr[i+1], suf[i+1]);
        }
        return suf;
    }
};

int main(){
    Solution sol;
    return 0;
}