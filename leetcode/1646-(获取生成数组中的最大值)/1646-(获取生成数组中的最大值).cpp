class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> d(n+1, 0);
        d[0] = 0;
        d[1] = 1;
        int mn = 1;
        for(int i=2; i<=n; ++i){
            if(i&1){
                d[i] = d[(i-1)/2] + d[(i-1)/2+1];
            }   
            else{
                d[i] = d[i/2];
            }
            if(d[i] > mn) mn = d[i];
        }
        return mn;
    }
};