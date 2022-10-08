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
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); ++i){
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(int i=0; i<nums.size(); ++i){
            if(pre[i] == pre[nums.size()]-pre[i]-nums[i]){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> v({2,1,2});
    cout<<sol.pivotIndex(v)<<endl;
    return 0;
}