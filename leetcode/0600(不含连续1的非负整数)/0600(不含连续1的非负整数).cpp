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