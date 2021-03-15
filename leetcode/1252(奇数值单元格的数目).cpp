#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>

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

    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans = 0;
        vector<vector<int>> mat(n);
        for(int i=0; i<n; ++i){
            mat[i].resize(m);
        }

        for(int i=0; i<indices.size(); ++i){
            for(int j=0; j<m; ++j){
                ++mat[indices[i][0]][j];
            }
            for(int j=0; j<n; ++j){
                ++mat[j][indices[i][1]];
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j] & 1){
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;

    return 0;
}