class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        map<long long, bool> vis;
        pq.push(1L);
        vis[1] = true;
        int cnt = 0;
        while(!pq.empty()){
            int tp = pq.top(); pq.pop(); ++cnt;
            if(cnt == n) return tp;            
            for(auto &x : primes){
                long long val = ((long long)x) * tp;
                if(!vis[val]) {
                    pq.push(val);
                    vis[val] = true;
                }
            }
        }
        return -1;
    }
};