class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 1;
        while(left != right){
            left >>= 1;
            right >>= 1;
            cnt  <<= 1;
        }
        return left * cnt;
    }
};