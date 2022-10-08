# 题目
`https://leetcode-cn.com/problems/circular-array-loop/`

# 题意
给你一个循环数组nums（从左往右访问到最后一个元素后下一个元素是第一个元素；从右往左访问到第一个元素后下一个元素是第一个元素），判断其是否**存在**一个序列[x1, x2, ..., xm, x1]，从nums的下标为x1的元素开始访问，最后回到下标为xi的元素。  

需要额外满足的条件是： x1 ne x2 ne x3  .. ne xm，即序列内的元素不能是同一个元素。

# 解法1：模拟
由于题目规模N最大为5000， 所以O(n^2)也不会超时。

我下面直接遍历每个下标，判断以该下标为起点是否存在循环，序列存在tmp中，对tmp进行判断。

因为使用了map，故我的时间复杂度是O(n^2 * log(n))， 可以用数组做map达到O(n^2)。

空间复杂度为O(n)


```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            map<int, bool> vis;
            int j = i;
            vector<int> tmp;
            vis[i] = true;
            tmp.push_back(i);
            int z=0, f=0;
            if(nums[i] > 0) ++z;
            else ++f;
            while(true){
                j = (j+nums[j]+nums.size()) % nums.size();
                if(!vis[j]){
                    vis[j] = true;
                    tmp.push_back(j);
                    if(nums[j]>0) ++z;
                    else ++f;
                }
                else{
                    tmp.push_back(j);
                    break;
                }
            }
            if(tmp.size()>2 && (f==tmp.size()-1 || z==tmp.size()-1) && tmp[0]==tmp.back()){
                return true;
            }
        }
        return false;
    }
};
```

# 官方题解
- 利用快慢指针原理，如果遍历的形状是`6`或者`0`，都可以认为返回true。
- 如果从某个起点开始的遍历没有环；或者指向了本身，如[2, 2], [3, 3, 3], 我们将遍历路径置j对应的nums[j]置为0，表示如果从该点j继续访问，不可能遇到环或者不满足返回true的条件。
- 快慢指针相遇了，证明有环，但还需特判这个环不能是自环。利用slow != nxt(slow)判断即可
- 判断方向`nums[slow]*nums[fast]>0 && nums[slow]*nums[nxt(fast)]>0`前者保证[0, 1, 3, 5, 7...]同向，后者保证[0, 2, 4, 6...]同向，这样就保证了遍历同向
- 置0的时候也要保证同向。
- 模运算需要注意，`(idx+nums[idx]+n)%n`是错误的模法，当idx+nums[idx]< -n时，将导致整体结果为负数而出错。

```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto nxt = [&](int idx){
            return ((idx + nums[idx])%n + n) % n;
        };
        for(int i=0; i<n; ++i){
            if(!nums[i]) continue;
            int slow = i;
            int fast = nxt(i);
            while(nums[slow]*nums[fast]>0 && nums[slow]*nums[nxt(fast)]>0){
                if(slow == fast){
                    if(slow != nxt(slow)){
                        return true;
                    }
                    else{
                        break;
                    }
                }
                slow = nxt(slow);
                fast = nxt(nxt(fast));
            }
            int idx = i;
            while(nums[idx] * nums[nxt(idx)] > 0){
                int nidx = nxt(idx);
                nums[idx] = 0;
                idx = nidx;
            }
        }
        return false;
    }
};
```

