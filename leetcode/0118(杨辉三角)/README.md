# 题目
`https://leetcode-cn.com/problems/pascals-triangle/`

# 思路
- 生成杨辉三角形
- 找规律，这里默认存在第-1列，值为0

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<numRows; ++i){
            int one=0, two=0;
            vector<int> tmp;
            int sz = ans[i-1].size();
            for(int j=-1; j<sz; ++j){
                if(j==-1) one = 0;
                else one = ans[i-1][j];
                if(j+1==ans[i-1].size()) two = 0;
                else two = ans[i-1][j+1];
                tmp.push_back(one + two);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
```


# 之前写的
```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; ++i){
            vector<int> temp;
            for(int j=0; j<=i; ++j){
                if(j==0 || j==i){
                    temp.push_back(1);
                }
                else if(j!=i){
                    temp.push_back(res[i-1][j]+res[i-1][j-1]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v = sol.generate(5);
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[i].size(); ++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
```