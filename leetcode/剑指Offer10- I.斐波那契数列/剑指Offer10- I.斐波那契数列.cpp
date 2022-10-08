class Solution {
public:
    int fib(int n) {
        int one = 0;
        int two = 1;
        int thr = 1;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=2; i<=n; ++i){
            thr = (one + two) % 1000000007;
            one = two;
            two = thr;
        }
        return thr;
    }
};