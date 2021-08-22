# 题目
`https://leetcode-cn.com/problems/reshape-the-matrix/`

# 思路
将矩阵reshape，纯模拟

```cpp
class Solution {
public:

    void nxt(int &dx, int &dy, int rc){
        ++dy;
        if(dy>=rc){
            dy = 0;
            ++dx;
        }
    };

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int rr = mat.size();
        if(rr==0){
            if(r*c==0) return vector<vector<int>>();
            else return mat;
        }
        int rc = mat[0].size();
        if(rr*rc == r*c){
            

            vector<vector<int>> ans(r, vector<int>(c, 0));
            int cx=0, cy=0;
            for(int i=0; i<r; ++i){    
                for(int j=0; j<c; ++j){
                    ans[i][j] = mat[cx][cy];
                    nxt(cx, cy, rc);

                }
            }
            return ans;
        }
        else{
            return mat;
        }
    }
};
```



# 之前写的

```cpp
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
```