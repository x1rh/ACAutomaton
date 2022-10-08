#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    int missingNumber(vector<int>& nums) {
        int sum = (1+nums.size())*nums.size()/2;
        for(int i=0; i<nums.size(); ++i){
            sum -= nums[i];
        }
        return sum;

    }
};

int main(){
    Solution sol;
    vector<int> v({9,6,4,2,3,5,7,0,1});
    cout<<sol.missingNumber(v)<<endl;
    return 0;
}