#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int br = nums.size();
        if(br==0) return nums;
        int bc = nums[0].size();
        if(br*bc < r*c) return nums;
        vector<vector<int>> res;
        vector<int> tmp(c);
        int cnt = 0;
        for(int i=0; i<br; ++i){
            for(int j=0; j<bc; ++j){
                tmp[cnt++] = nums[i][j];
                if(cnt==c){
                    res.push_back(tmp);
                    cnt = 0;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v({{1,2},{3,4}});
    vector<vector<int>> res = sol.matrixReshape(v, 1, 4);
    print(res);
    return 0;
}