# 题目
https://leetcode-cn.com/problems/friends-of-appropriate-ages/  

# 思路
设3个条件为A， B， C， 则：
A || B || C, 且C ⊆ B， 则 A || B || C = A||B, 即满足条件`0.5*x+7 < y <= x`即可。此外，解不等式知，x必须大于15。

先对ages排序，然后枚举每一个x，用双指针维护y的取值范围即可。


```cpp
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int l=0, ans=0, r=0; 
        int n = ages.size();
        for(int i=0; i<ages.size(); ++i){
            int x = ages[i];
            if(x < 15) continue;
            while(l<n && 0.5*x+7 >= ages[l]) ++l;
            while(r+1<n && ages[r+1]<=x) ++r;
            ans += r - l;
        }
        return ans;
    }
};
```

注意r的取值范围，是[0, n-1]， l的取值范围是[0, n]， 这里比较晦涩，这么做是为了保证l永远多加1，而r永远在正确的位置（没有多加1）


