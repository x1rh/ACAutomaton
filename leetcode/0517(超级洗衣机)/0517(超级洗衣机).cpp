class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        
        int sm = accumulate(machines.begin(), machines.end(), 0);
        if(sm % machines.size() != 0) return -1;
        int avg = sm / machines.size();
        int ans = 0, ta = 0;
        for(auto &x : machines){
            x -= avg;
            ta += x;
            ans = max(ans, max(abs(ta), x));
        }

        return ans;
    }
};