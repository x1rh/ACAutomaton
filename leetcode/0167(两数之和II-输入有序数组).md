# 题目
https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/


# 思路
对已排序的数组，从中找出和位target的两个数，二分即可。



```cpp
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

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0; i<numbers.size(); ++i){
            auto it = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]);
            if(it!=numbers.end() && *it==target-numbers[i]){
                res.push_back(i+1);
                res.push_back(distance(numbers.begin()+i+1, it)+i+2);
                break;
            }
        }
        return res;
    }
};

int main(){

    Solution sol;
    vector<int> v({2, 7, 11, 15});
    vector<int> res = sol.twoSum(v, 9);
    print(res);


    return 0;
}
```


Go版
```go
func twoSum(numbers []int, target int) []int {
    for i, x := range numbers {
        l := i+1
        r := len(numbers)-1
        tar := target - x
        for ; l<=r; {
            mid := l + (r-l)>>1
             
            if numbers[mid] == tar {
                return []int{i+1, mid+1}
            } else if tar > numbers[mid]{
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }
    return []int{}
}
```