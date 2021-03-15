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

    // 常规思路, 桶排
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     vector<int> res;
    //     vector<int> mp(1+nums.size(), 0);
    //     for(int i=0; i<nums.size(); ++i){
    //         ++mp[nums[i]];
    //     }
    //     for(int i=1; i<mp.size(); ++i){
    //         if(mp[i] == 0){
    //             res.push_back(i);
    //         }
    //     }
    //     return res;
    // }

    // 引申思路, 类似映射的思想
    // 将数组中下标为nums[i]的数置为负数, 之后再次循环可以得到非负数的下标
    vector<int> findDisappearedNumbers(vector<int>& nums){
        vector<int> res;
        int idx = 0;
        for(int i=0; i<nums.size(); ++i){
            idx = abs(nums[i]) - 1;
            nums[idx] = abs(nums[idx]) * (-1);
        }
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] > 0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v({4,3,2,7,8,2,3,1});
    vector<int> res = sol.findDisappearedNumbers(v);
    print(res);
    return 0;
}