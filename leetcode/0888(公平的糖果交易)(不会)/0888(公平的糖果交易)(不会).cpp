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
    // sum1-x+y = sum2-y+x
    // y = x + (sum2-sum1)/2
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1=0, sum2=0;
        for(int i=0; i<A.size(); ++i) sum1+=A[i];
        for(int i=0; i<B.size(); ++i) sum2+=B[i];
        vector<int> res(2, 0);
        int delta = (sum2-sum1)/2;

        int cha = abs(sum2-(sum1+sum2)/2);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int pre = 0;
        for(int i=0; i<A.size(); ++i){
            pre = lower_bound(B.begin()+pre, B.end(), A[i]+delta) - B.begin();
            if(pre!=B.size() && B[pre]==A[i]+delta){
                res[0] += A[i];
                res[1] += B[pre];
                cha -= abs(A[i]-B[pre]);
                if(cha==0) break;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> A({1,2,5});
    vector<int> B({2,4});
    vector<int> res = sol.fairCandySwap(A, B);
    print(res);
    return 0;
}