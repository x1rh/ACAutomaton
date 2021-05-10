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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, j=0, len=nums.size(), ans=0;
        while(i<len){
            if(nums[i] == 0){
                ++i;
                continue;
            }
            else{
                j = i+1;
                while(j<len && nums[j]==1) ++j;
                if(ans < j-i){
                    ans = j-i;
                }
            }
            i = j;
            if(j >= len) break;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({1,1,0,1,1,1});
    cout<<sol.findMaxConsecutiveOnes(v)<<endl;
    return 0;
}