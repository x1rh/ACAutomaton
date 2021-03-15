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
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        int i=0, len=nums.size(), j=nums.size()-1;
        while(i<len && nums[i]==cp[i]) ++i;
        while(j>=0 && nums[j]==cp[j]) --j;
        return j-i+1>0?j-i+1:0;
    }
};

int main(){
    Solution sol;
    vector<int> v({2, 6, 4, 8, 10, 9, 15});
    cout<<sol.findUnsortedSubarray(v)<<endl;

    return 0;
}