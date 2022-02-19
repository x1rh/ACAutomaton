# 题目
[717. 1比特与2比特字符](https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/)

# 题意
一个只包含0和1的比特序列，要求最后一个元素是0， 下标0~n-1的比特可以随意组合，有三种组合方式：0或者10或者11。判断序列在最后一位是0的前提下，是否可以划分为任意这三种比特组合的组合。

# 思路
实际上只有两种划分，1X和0，这两种是互斥的，所以直接循环划分即可。


Go
```go
func isOneBitCharacter(bits []int) bool {
    i := 0
    n := len(bits)
    ans := true

    for i< n - 1 {
        if bits[i] == 1 {
            if i+1<n-1 {
                i += 2           
            } else {
                ans = false
                break 
            }
        } else {
            i += 1
        } 
    }
    return ans 
}
```


cpp
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
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i=0, j=0;
        while(i<len){
            if(bits[i]==0){
                j = i;
                ++i;
            }
            else{
                i = i+2;
            }
        }
        if(i==j+1) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    vector<int> v({});
    cout<<sol.isOneBitCharacter(v)<<endl;
    return 0;
}
```