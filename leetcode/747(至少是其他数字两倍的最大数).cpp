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
    int dominantIndex(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int idx = -1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] > first){
                second = first;
                first = nums[i];
                idx = i;
            }
            else if(nums[i] > second){
                second = nums[i];
            }
        }
        if(second*2 <= first) return idx;
        else return -1;
    }
};

int main(){
    Solution sol;
    vector<int> v({0,0,3,2});
    cout<<sol.dominantIndex(v)<<endl;
    return 0;
}