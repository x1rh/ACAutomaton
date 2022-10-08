# 题目
`https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/`

# 思路
求所有大于0且小于等于n的数中，二进制心态下数位上没有连续1的数的个数

解法：dp [看这个题解](https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/solution/suan-fa-xiao-ai-wo-lai-gei-ni-jie-shi-qi-4nh4/)

将所有小于n的数的二进制形态用完全二叉树表示，根节点为最低位。

设dp[t]表示高度为t-1、根节点为0的满二叉树中，不包含连续1的从根节点到叶节点的路径数量。

dp[t] = dp[t-1] + dp[t-2]  t>=2
dp[t] = 1                  t<2 


pre表示上一层是1还是0




```cpp
class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<31; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }

        int pre=0, res=0;
        for(int i=29; i>=0; --i){
            int v = 1<<i;

            // 判断当前层根节点是1还是0，如果为true,则说明有右子树，则可以把左子树加上,再继续处理右子树的左子树
            if((v&n)!=0){    
                res += dp[i+1];
                if(pre==1){   // 上一层为1，这一层也为1，则右子树不必继续处理
                    break;
                }
                pre = 1;
            }
            else{
                pre = 0;
            }
            if(i==0) {
                res += 1;
            }
        }
        return res;
    }
};
```