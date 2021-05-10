#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

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
    bool isMonotonic(vector<int>& A) {
        int sz = A.size();
        if(sz<=2) return true;
        bool f1=true, f2=true;

        for(int i=1; i<sz; ++i){
            if(A[i]<A[i-1]) {
                f1 = false;
                break;
            }
        }

        for(int i=1; i<sz; ++i){
            if(A[i]>A[i-1]) {
                f2 = false;
                break;
            }
        }

        return f1 || f2;
    }
};

int main(){
    Solution sol;

    return 0;
}