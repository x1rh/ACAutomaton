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
    // 解法1, 直接按leetcode118构造
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i=0; i<rowIndex+1; ++i){
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
        return res[res.size()-1];
    }

    // 解法2, 求组合数C(n, i) 枚举i从0到n (喜闻乐见想了想发现33阶乘会爆longlong)
    // 解法3, 根据组合数公式, 再利用C(n, i) 和C(n, i+1)之间的递推关系, 即C(n, i+1) = (n-i)/(i+1) * C(n, i)
};

int main(){
    Solution sol;
    vector<int> v = sol.getRow(3);
    print(v);
    return 0;
}