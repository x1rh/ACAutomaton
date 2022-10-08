class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        const double exp = 0.0000000001;
        double x = log(n) / log(3) * 1.0;
        int ix = x+exp;
        if(fabs(x-ix)<exp) return true;
        else return false;
    }
};