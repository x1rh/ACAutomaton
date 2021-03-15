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

    // 求prices[j] - prices[i](>=0)的最大值
    // 解法1, 暴力
    // int maxProfit(vector<int>& prices) {
    //     int ans = 0, temp;
    //     if(prices.size()<=1) return 0;
    //     for(int i=0; i<prices.size()-1; ++i){
    //         for(int j=i+1; j<prices.size(); ++j){
    //             temp = prices[j] - prices[i];
    //             if(ans < temp){
    //                 ans = temp;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // 解法2， dp
    // 定义dp[i]为前i天的最大收益, min_prices为前i天的最小价格
    // dp[i+1] = max(dp[i], prices[i+1]-min_prices)
    int maxProfit(vector<int>& prices){
        if(prices.size()<1) return 0;
        int ans = 0;
        vector<int> dp(prices.size());
        dp[0] = 0;
        int min_price = prices[0];
        for(int i=1; i<prices.size(); ++i){
            dp[i] = max(dp[i-1], prices[i]-min_price);
            if(dp[i] > ans){
                ans = dp[i];
            }
            if(prices[i] < min_price){
                min_price = prices[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({7,1,5,3,6,4});
    cout<<sol.maxProfit(v)<<endl;
    // print(v);
    return 0;
}