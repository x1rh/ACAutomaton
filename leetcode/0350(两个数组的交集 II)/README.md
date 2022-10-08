# 题目
`https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/`

# 思路
求两个数组的交集，这两个数组可能并不满足集合的定义（含有重复元素），所以交集可能也含有重复的元素  
用3个map做这题，一个记录交集，另外两个分别记录个数

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2, mp3;
        for(auto &x : nums1){
            mp1[x] += 1;
            if(!mp3[x]) {
                mp3[x] = 1;
            }
        }
        for(auto &x : nums2){
            mp2[x] += 1;
            if(mp3[x]==1){
                mp3[x] = 2;
            } 
        }
        vector<int> ans;
        for(auto &[k, v] : mp3){
            if(v==2){
                int lp = min(mp1[k], mp2[k]);
                for(int i=0; i<lp; ++i){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
```

