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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n);
        for(int i=0; i<n; ++i){
            ans[i].resize(m);
        }

        vector<int> col(n);

        for(int kase=0; kase<k; ++kase){
            for(int i=0; i<n; ++i){
                col[i] = grid[i][m-1];
            }
            for(int j=m-1; j>=1; --j){
                for(int i=0; i<n; ++i){
                    grid[i][j] = grid[i][j-1];
                }
            }
            grid[0][0] = col[n-1];
            for(int i=0; i<n-1; ++i){
                grid[i+1][0] = col[i];
            }
        }
        return grid;
    }

};

int main(){
    Solution sol;
    vector<vector<int>> grid({{1,2,3},{4,5,6},{7,8,9}});
    sol.shiftGrid(grid, 1);
    print(grid);
    return 0;
}