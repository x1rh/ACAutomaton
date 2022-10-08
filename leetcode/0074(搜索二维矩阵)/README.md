# 题目
`https://leetcode-cn.com/problems/search-a-2d-matrix/`

# 思路
在一个每一行有序的且上一行的最后一个元素小于下一行的第一个元素的二维矩阵中寻找元素x


# 解法1 每行二分，时间复杂度O(nlogn)
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); ++i){
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(it!=matrix[i].end() && target==*it){
                return true;
            }
        }
        return false;
    }
};
```


# 解法2 直接二分，时间复杂度O(log2(mn))

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0, r=m*n-1;
        while(l<=r){
            int mid = (l+r) / 2;
            int x = mid/n;
            int y = mid - x*n;
            assert(x>=0);
            assert(y>=0);
            if(matrix[x][y] == target){
                return true;
            }
            else if(matrix[x][y]<target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};
```


解法3 两次二分， 先按第一列进行二分，判断出在哪一行，然后再在那一行里二分
