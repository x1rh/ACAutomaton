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
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int even=0, val, idx;
        vector<int> ans(queries.size());
        for(int i=0; i<A.size(); ++i){
            if(!(A[i]&1)) even += A[i];
        }
        for(int i=0; i<queries.size(); ++i){
            val = queries[i][0];
            idx = queries[i][1];

            A[idx] += val;

            if(A[idx]&1){
                if(val&1){
                    even -= A[idx] - val;
                }
            }
            else{
                if(val&1){
                    even += A[idx];
                }
                else{
                    even += val;
                }
            }
            ans[i] = even;
        }
        return ans;
    }
};

int main(){
    Solution sol;

    return 0;
}