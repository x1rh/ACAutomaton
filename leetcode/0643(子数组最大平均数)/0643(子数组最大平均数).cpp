#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    // 定义pre[i] 为求和nums[j]  j从0到i-1
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> pre(nums.size());
        if(nums.size() == 0) return 0;
        pre[0] = 0;
        double ans = -numeric_limits<double>::max(), temp;
        for(int i=1; i<nums.size(); ++i){
            pre[i] += pre[i-1] + nums[i-1];
        }
        for(int i=k-1; i<nums.size(); ++i){
            temp = pre[i]-pre[i-k+1] + nums[i];
            if(temp > ans) ans = temp;
        }
        return ans / ((double)k);
    }
};

int main(){
    Solution sol;
    vector<int> v({-1});
    // cout<<sol.findMaxAverage(v, 1)<<endl;
    cout<< ( 1 > numeric_limits<double>::min()) <<endl;
    return 0;
}