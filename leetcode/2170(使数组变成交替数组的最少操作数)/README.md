# 题目
- 280场周赛-第2题
- [2170. 使数组变成交替数组的最少操作数](https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-alternating/)

# 题意
- 要求奇数下标全为同一个数x、偶数下标同为一个数y，且x不等于y
- 求从原数组变成xyxyxy...这样的数组的最少修改项是多个


# 思路
求出奇数下标、偶数下标出现次数最多的项：
- 如果这两个项值不等，后续非常好计算
- 如果这两个项值相等，那么就要分别讨论出现次数第二多的项


```cpp
class Solution {
public:
    map<int, int> cal(vector<int> &nums, int st){
        map<int, int> mp;
        mp[nums[st]] += 1;
        
        for(int i=st+2; i<nums.size(); i+=2){
            mp[nums[i]] += 1;
        }
        return mp; 
    }
    
    pair<int, int> kv(map<int, int>& mp){
        int max_k = -1;
        int max_v = -1;
        for(auto [k, v] : mp){
            if(v > max_v){
                max_v = v;
                max_k = k;
            }
        }
        return {max_k, max_v};
    }
    
    
    int minimumOperations(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        
        auto mp1 = cal(nums, 0);
        auto mp2 = cal(nums, 1);
        auto p1 = kv(mp1);
        auto p2 = kv(mp2);
        int len1 = nums.size() / 2 + ((int)(nums.size()&1));
        int len2 = nums.size() / 2;
        
        if(p1.first != p2.first){
            return len1-p1.second + len2-p2.second;
        } else {
            
            // 改前面
            int x = 0;
            if(mp1.size() == 1){
                x = 0; 
            } else {
                mp1[p1.first] = 0;
                for(auto &[k, v] : mp1){
                    if(v > x){
                        x = v;
                    }
                }  
            }
            int one = len1 - x + len2-p2.second;
                
            
            int y = 0;
            if(mp2.size() == 1){
                y = 0;
            } else {
                mp2[p2.first] = 0;
                for(auto &[k, v] : mp2){
                    if(v > y){
                        y = v;
                    }
                }
            }
            // 改后面
            int two = len1-p1.second + len2 - y;
            return min(one, two);
        }
    }
};

```

。。。写吐了，感觉代码能力还是弱了，写了近一个小时。。。