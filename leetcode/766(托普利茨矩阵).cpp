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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row<=1) return true;
        int col = matrix[0].size();
        for(int i=0; i<row; ++i){
            int idx = 1;
            for(int j=i+1; j<row&&idx<col; ++j, ++idx){
                if(matrix[j][idx] != matrix[j-1][idx-1]){
                    return false;
                }
            }
        }

        for(int i=0; i<col; ++i){
            int idx = 1;
            for(int j=i+1; j<col&&idx<row; ++j, ++idx){
                if(matrix[idx][j] != matrix[idx-1][j-1]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> v({{1},{2}});
    cout<<sol.isToeplitzMatrix(v)<<endl;
    return 0;
}