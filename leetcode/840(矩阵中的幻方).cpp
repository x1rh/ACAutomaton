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
    bool vis[16];
    bool check_pos(int row, int col, int i, int j){
        return i+2<row && j+2<col;
    }

    bool check_mat(vector<vector<int>>& grid, int ii, int jj){
        int row = grid.size();
        int col = grid[0].size();
        int sum = 0;
        memset(vis, 0, sizeof(vis));
        for(int i=ii; i<ii+3; ++i){
            sum = 0;
            for(int j=jj; j<jj+3; ++j){
                sum += grid[i][j];
                vis[grid[i][j]] = true;
            }
            if(sum != 15){
                return false;
            }
        }

        for(int i=1; i<=9; ++i){
            if(!vis[i]) return false;
        }

        for(int i=jj; i<jj+3; ++i){
            sum = 0;
            for(int j=ii; j<ii+3; ++j){
                sum += grid[j][i];
            }
            if(sum != 15){
                return false;
            }
        }
        sum = 0;
        for(int i=0; i<3; ++i){
            sum += grid[ii+i][jj+i];
        }
        if(sum != 15) return false;
        sum = 0;
        for(int i=0; i<3; ++i){
            sum += grid[ii+i][jj+2-i];
        }
        if(sum != 15) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int ans = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(check_pos(row, col, i, j)){
                    if(check_mat(grid, i, j)){
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v({{4,3,8,4},{9,5,1,9},{2,7,6,2}});
    cout<<sol.check_mat(v, 0, 0)<<endl;
    cout<<sol.numMagicSquaresInside(v)<<endl;

    return 0;
}