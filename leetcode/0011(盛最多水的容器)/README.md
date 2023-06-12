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


随便选取两条线段l和r，然后确定两者中最小的那条，假设为l
考虑这两条线段中间的所有线段x, 让x和l围成目标区域：
- 如果`x<l`，那么x不可能是答案，因为如果要选x，长和宽都会减小
- 如果`x>l`，那么方案(l, x)也不会比方案(l, r)更优, 长减小，宽不变
这意味着当方案(l,r)考虑后，便可以直接移动较短的那条边，考虑下一个方案，对所有的方案取个最大值即可


