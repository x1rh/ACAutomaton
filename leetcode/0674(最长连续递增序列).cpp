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
    // 双指针法
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int i=0, j=0, ans=0;
        while(i<len){
            j = i+1;
            while(j<len && nums[j]>nums[j-1]){
                ++j;
            }
            if(j-i>ans){
                ans = j-i;
            }
            i = j;
            if(j>=len) break;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v{2,2,2,2,2};
    cout<<sol.findLengthOfLCIS(v)<<endl;
    return 0;
}