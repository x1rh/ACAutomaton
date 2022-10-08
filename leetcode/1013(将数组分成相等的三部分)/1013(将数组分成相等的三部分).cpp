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
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> pre(A.size()+1, 0);
        for(int i=1; i<=A.size(); ++i){
            pre[i] = pre[i-1]+A[i-1];
        }
        int thi = pre[A.size()];
        int one = thi / 3;
        int two = one * 2;
        bool f1=false, f2=false;
        if(one*3 != thi) return false;
        else{
            for(int i=0; i<=A.size(); ++i){
                if(!f1 && !f2 && pre[i]==one){
                    f1 = true;
                }
                else if(f1 && !f2 && pre[i]==two){
                    return true;
                }
            }
            return false;
        }
    }
};

int main(){
    Solution sol;
    vector<int> v({6,1,1,13,-1,0,-10,20});
    cout<<sol.canThreePartsEqualSum(v)<<endl;
    return 0;
}