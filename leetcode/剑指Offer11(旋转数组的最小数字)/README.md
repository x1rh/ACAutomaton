# 题目
`https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/`

# 思路

注意第3种情况：
当numbers[mid] == nums[r]的时候，我们将r减1



```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l=0, r=numbers.size()-1, mid;
        while(l<r){
            mid = l + (r-l)/2;
            if(numbers[mid] < numbers[r]){
                r = mid; 
            }
            else if(numbers[mid] > numbers[r]){
                l = mid + 1;
            }
            else{
                --r;
            }
        }
        return numbers[l];
    }
};
```