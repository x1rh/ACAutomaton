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
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;
        int i, j;
        for(i=1; i<A.size()&&A[i]>A[i-1]; ++i);
        for(j=i; j<A.size()&&A[j]<A[j-1]; ++j);
        if(i!=1 && i!=A.size() && j==A.size()) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    vector<int> v({0,3,2,1});
    cout<<sol.validMountainArray(v)<<endl;
    return 0;
}