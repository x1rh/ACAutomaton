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
    // 双指针法(莫名奇妙做对了...一发入魂)
    // 运行时间2s, 有点久, 复杂度应该是O(n^2)
    // 大致思路为枚举买入时间k, 令i=k. k取值范围为[0, prices.size()-1]
    // 则与这次买入对应的卖出时间j满足条件:
    // (1) 时间i到时间j内股价不降
    // (2) 在满足条件(1)的情况下, 取最大的prices[j]
    // 这仅仅为一次买入卖出, 后续的买入卖出同理
    // 一次买入卖出后，指针更新操作为i=j+1, j=i+1;
    // 直到i>=prices.size() 或者j>=prices.size() 则认为以这一次从时间k开始的买入卖出的收入为ans
    int maxProfit(vector<int>& prices){
        int len = prices.size();
        int res = 0;
        for(int k=0; k<len; ++k){
            int ans=0, i=k;
            while(i<len){
                int temp=prices[i], p=i;
                int j=i+1;
                while(j<len){
                    if(temp < prices[j]){
                        temp = prices[j];
                        p = j;
                        ++j;
                    }
                    else{
                        break;
                    }
                }
                ans += prices[p] - prices[i];
                i = j;
                if(j>=len) break;
            }
            if(ans > res) res = ans;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,2,3,4,5});
    cout<<sol.maxProfit(v)<<endl;
    // print(v);
    return 0;
}