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
    // 统计前面有多少个0, 一次性向前移动cnt位
    void moveZeroes(vector<int>& nums) {
        int i=0, cnt=0, j=0;
        while(i<nums.size()){
            if(nums[i]!=0) ++i;
            else{
                ++cnt;
                j = i+1;
                while(j<nums.size()){
                    if(nums[j]!=0){
                        nums[j-cnt] = nums[j];
                        ++j;
                    }
                    else{
                        i = j;
                        break;
                    }
                }
                if(j>=nums.size()) break;
            }
        }
        for(int i=nums.size()-cnt; i<nums.size(); ++i){
            nums[i] = 0;
        }
    }
};

int main(){
    Solution sol;
    vector<int> v({0,1,0,3,12});
    sol.moveZeroes(v);
    print(v);

    return 0;
}