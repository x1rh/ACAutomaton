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
    const int dx[2] = {-1, 1};
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2) return true;
        int len=nums.size();
        int i=1;
        while(i<len && nums[i]>=nums[i-1]) ++i;
        if(i>=len-1) return true;
        int j=i+1;
        while(j<len && nums[j]>=nums[j-1]) ++j;
        if(j>=len){
            if(i==1 || nums[i+1]>=nums[i-1] || nums[i]>=nums[i-2]) return true;
            else return false;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> v({-1, 4, 2, 3});
    cout<<sol.checkPossibility(v)<<endl;
    return 0;
}