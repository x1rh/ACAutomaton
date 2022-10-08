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
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> ans(A.size());
        for(int i=0; i<A.size(); ++i){
            num = (A[i] + (num*2%5))%5;
            if(num%5 == 0){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({6,1,1,13,-1,0,-10,20});
    cout<<sol.canThreePartsEqualSum(v)<<endl;
    return 0;
}