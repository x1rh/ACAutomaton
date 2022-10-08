# 题目
`https://leetcode-cn.com/problems/B1IidL/`


# 思路
- 题目保证了山峰的存在
- 二分，判断mid是不是山峰，不是的话，快速爬坡
- trick，设置l=1, r=n-2, 保证mid-1合法，此外考虑第一点。

```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l=1, r=n-2;
        while(l<=r){
            int mid = l + (r-l)/2;
            if((arr[mid-1]<arr[mid]) && (arr[mid]>arr[mid+1])){
                return mid;
            }
            else if((arr[mid-1]<arr[mid]) && (arr[mid]<arr[mid+1])){
                l = mid + 1;
            }
            else{
                r = mid -1;
            }m
        }
        return -1;
    }
};
```