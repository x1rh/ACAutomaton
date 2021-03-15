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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> res(col);
        for(int i=0; i<col; ++i){
            vector<int> temp(row);
            for(int j=0; j<row; ++j){
                temp[j] = A[j][i];
            }
            res[i] = temp;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v({{1,2,3},{4,5,6},{7,8,9}});
    vector<vector<int>> res = sol.transpose(v);
    print(res);
    return 0;
}