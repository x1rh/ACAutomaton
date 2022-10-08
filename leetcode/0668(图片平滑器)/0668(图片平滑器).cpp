#include <iostream>
#include <vector>

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
    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int sum, cnt;
        vector<vector<int>> res(M.size());
        for(int i=0; i<M.size(); ++i){
            for(int j=0; j<M[i].size(); ++j){
                sum = M[i][j];
                cnt = 1;
                for(int k=0; k<8; ++k){
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if(x<0 || x>=M.size() || y<0 || y>=M[0].size()) continue;
                    sum += M[x][y];
                    ++cnt;
                }
                // cout<<"("<<i<<", "<<j<<")"<<sum<<" "<<cnt<<endl;
                res[i].push_back(sum/cnt);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v({{1,1,1},{1,0,1},{1,1,1}});
    vector<vector<int>> res = sol.imageSmoother(v);
    print(res);
    return 0;
}