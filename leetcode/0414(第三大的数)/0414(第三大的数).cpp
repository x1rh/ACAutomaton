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
    // O(nlogn)
    // int thirdMax(vector<int>& nums) {
    //     if(nums.size() == 0) return 0;
    //     else if(nums.size() == 1) return nums[0];
    //     else if(nums.size() == 2) return max(nums[0], nums[1]);
    //     else{
    //         sort(nums.begin(), nums.end());
    //         auto it = unique(nums.begin(), nums.end());
    //         if(distance(nums.begin(), it)<3) return *(it-1);
    //         else return *(it-3);
    //     }
    // }

    // O(3n) ~ O(n)
    // 测试样例中存在最小的int值, 所以要开个flag判断是否有int最小值出现
    // int thirdMax(vector<int>& nums) {
    //     bool flag=false;
    //     if(nums.size() == 0) return 0;
    //     else if(nums.size() == 1) return nums[0];
    //     else if(nums.size() == 2) return max(nums[0], nums[1]);
    //     else{
    //         int first = numeric_limits<int>::min();
    //         int second = first;
    //         int third = first;
    //         for(int i=0; i<nums.size(); ++i){
    //             if(nums[i]>first) first = nums[i];
    //         }
    //         for(int i=0; i<nums.size(); ++i){
    //             if(nums[i]!=first && second<nums[i]) second=nums[i];
    //         }
    //         for(int i=0; i<nums.size(); ++i){
    //             if(nums[i]!=first && nums[i]!=second && third<=nums[i]) {
    //                 third = nums[i];
    //                 flag = true;
    //             }
    //         }
    //         if(!flag) return first;
    //         else return third;
    //     }
    // }

    // O(n)
    int thirdMax(vector<int>& nums) {
        int first = numeric_limits<int>::min();
        int second = first;
        int third = first;
        int f1 = 0;  // first被赋值几次, 可以换成布尔型的flag
        int f2 = 0;  // second被赋值几次
        int f3 = 0;  // third被赋值几次

        for(int i=0; i<nums.size(); ++i){
            if(nums[i] >= first){
                if(nums[i] == first) {  // 遇到重复出现的值直接continue
                    if(f1 == 0) ++f1;   // 特判是否出现int最小值
                    continue;
                }
                if(f2 != 0){           // 只有当second被更赋值过才能给third赋值
                    third = second;
                    ++f3;
                }
                if(f1 != 0){           // 只有first被赋值过才能给second赋值
                    second = first;
                    ++f2;
                }
                first = nums[i];
                ++f1;
            }
            else if(nums[i]<first && nums[i]>=second){
                if(nums[i] == second) {
                    if(f2 == 0) ++f2;
                    continue;
                }
                if(f2 != 0){
                    third = second;
                    ++f3;
                }
                second = nums[i];
                ++f2;
            }
            else if(nums[i]<second && nums[i]>=third){
                if(nums[i] == third) {
                    if(f3 == 0) ++f3;
                    continue;
                }
                third = nums[i];
                ++f3;
            }
        }
        if(f3 == 0) return first;
        else return third;
    }
};

int main(){
    Solution sol;
    vector<int> v({3, 2, 1});
    cout<<sol.thirdMax(v)<<endl;

    return 0;
}