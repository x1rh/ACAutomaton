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
    int fib(int N) {
         if(N == 0) return 0;
         if(N == 1) return 1;
        int f0=0, f1=1, f2;
        for(int i=2; i<=N; ++i){
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};

int main(){
    Solution sol;
    cout<<sol.fib(30)<<endl;

    return 0;
}