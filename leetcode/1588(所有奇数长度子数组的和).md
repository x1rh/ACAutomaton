# 题目
`https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/`


# 思路
枚举一个长度i（从1到n且为奇数），枚举一个起点j（从0到n-1），求和即可。

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        for(int i=1; i<=n; i+=2){
            for(int j=0; j<n; ++j){
                if(j+i>n) break;
                for(int k=j; k<n&&k<j+i; ++k){
                    ans += arr[k];
                }
            }
        }
        return ans;
    }
};
```