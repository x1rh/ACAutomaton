# 题目
`https://leetcode-cn.com/problems/single-number-iii/`


# 题意
一个数组nums中，只有两个数字x1, x2只出现了一次，其余的出现了两次，求这两个只出现了一次的数字。


思路：
- 先对数组nums求异或和，得x。 x = x1 ^ x2;
- 求出x中某个为1的数位，记其下标为idx。 idx的范围为[0, 31]。则x1和x2中一个第idx位为0, 另一个为1
- 再次遍历nums数组求异或和，将nums中每个第idx位为1的数全部分成一组与ans[0]求异或和，为0的部分为另一组与ans[1]求异或和，即可求得答案。





```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        for(auto &x : nums){
            xo ^= x;
        }

        int idx = -1;

        for(int i=31; i>=0&&(idx==-1); --i){
            if((xo>>i) & 1) idx = i;
        }

        vector<int> ans(2, 0);

        for(auto &x : nums){
            if((x>>idx)&1) {
                ans[0] ^= x;
            }
            else{
                ans[1] ^= x;
            }
        }
        return ans;
    }
};
```

哈希版
```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        vector<int> ans; 
        for(auto &x : nums){
            auto it = ump.find(x);
            if(it == ump.end() || it->first != x){
                ump[x] = 1;
            }
            else{
                it->second = 2;
            }
        }
        for(auto &[k, v] : ump){
            if(v==1){
                ans.push_back(k);
            }
        }

        return ans;
    }
};
```