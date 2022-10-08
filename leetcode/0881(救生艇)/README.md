# 题目
`https://leetcode-cn.com/problems/boats-to-save-people/`


# 思路
排序+贪心，要求两个人尽量能做一艘船。  
如果处理了最大和最小的这两个人，问题就变成了处理n-2个人过河的问题


```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()==0) return 0;
        if(people.size()==1) return 1;
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        int ans = 0;
        while(i<j){
            if(people[j] + people[i] > limit){
                --j;
                ++ans;
            }
            else{
                --j;
                ++i;
                ++ans;
            }
        }
        if(i==j) ++ans;
        return ans;
    }
};
```