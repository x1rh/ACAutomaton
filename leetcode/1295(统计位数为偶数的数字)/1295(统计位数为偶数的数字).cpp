#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
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
    int len(int x){
        int cnt = 0;
        while(x){
            ++cnt;
            x/=10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); ++i){
            if(!(len(nums[i])&1)){
                ++ans;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid({{1,2,3},{4,5,6},{7,8,9}});
    sol.shiftGrid(grid, 1);
    print(grid);
    return 0;
}