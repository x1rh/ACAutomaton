/*
构造反转数字的过程中判断是否溢出即可
*/


class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int reverse(int x) {
        int ans = 0;
        while(x){
            int mod = x % 10;
            int tmp = ans*10 + mod;
            if((tmp-mod)/10 != ans)
                return 0;
            else
                ans = tmp;
            x /= 10;
        }
        return ans;
    }
};