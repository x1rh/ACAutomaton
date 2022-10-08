# 题目
`https://leetcode-cn.com/problems/container-with-most-water/`


# 思路
求一个[l, r]使得其所能装的水最多

暴力会超时

解法1 双指针：
1. 令l=0, r=n-1; sum = 求和height[i ... j]
2. minor = min(height[l], height[r])
3. 每次移动的是矮的挡板。（如果移动高的挡板，sum只会减少）
4. 两个指针同时移动 是 只移动一个指针的子集
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r= height.size()-1;
        int ans = 0;
        while(l<=r){
            if(height[l]<height[r]){
                ans = max(ans, (height[l])*(r-l));
                ++l;
            }
            else{
                ans = max(ans, (height[r])*(r-l));
                --r;
            }
        }
        return ans;
    }
};
```


问题1： 为什么要令左右指针指向数组两端


