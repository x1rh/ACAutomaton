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
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size(), 0);
        int ii=1, jj=0;
        for(int i=0; i<A.size(); ++i){
            if(A[i]&1){
                res[ii] = A[i];
                ii += 2;
            }
            else{
                res[jj] = A[i];
                jj += 2;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3,4,4,3,2,1});
    vector<int> res = sol.sortArrayByParityII();
    print(res);
    return 0;
}