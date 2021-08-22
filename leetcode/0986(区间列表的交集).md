# 题目
``


# 思路
求两个区间数组中区间的交集


## 解法1 暴力枚举+求交集
```cpp
class Solution {
public:

    tuple<bool, int, int> intersect(int l1, int r1, int l2, int r2){
        if(r1 < l2) return {false, 0, 0};
        if(r2 < l1) return {false, 0, 0};
        if(l1<=l2 && l2<=r1 && r1<=r2){
            return {true, l2, r1};
        }
        if(l2<=l1 && l1<=r2 && r2<=r1){
            return {true, l1, r2};
        }
        if(l2<=l1 && r1<=r2) return {true, l1, r1};
        if(l1<=l2 && r2<=r1) return {true, l2, r2};
        return {false, 0, 0};
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans;
        for(int i=0; i<firstList.size(); ++i){
            int l1 = firstList[i][0];
            int r1 = firstList[i][1];
            for(int j=0; j<secondList.size(); ++j){
                int l2 = secondList[j][0];
                int r2 = secondList[j][1];
                auto [flag, x, y] = intersect(l1, r1, l2, r2);
                if(flag){
                    ans.push_back({x, y});
                }
            }
        }
        return ans;
    }
};
```


## 解法2： 合并
设区间数组A和区间数组B
- 求出A和B中最小的end， 设为A[0]的end
- 则A[0]最多只可能和B中的区间相交一次，然后剔除
- 重复这个过程

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        bool flag = false;
        vector<vector<int>> ans;
        for(int i=0, j=0; i<firstList.size()&&j<secondList.size();){
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if(l<=r){
                ans.emplace_back(vector<int>({l, r}));
            }
            if(firstList[i][1] < secondList[j][1]){
                ++i;
            }
            else{
                ++j;
            }
        }
        return ans;
    }
};
```