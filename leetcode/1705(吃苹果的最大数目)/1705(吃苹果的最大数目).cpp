typedef pair<int, int> pii;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int last = 0;
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i=0; i<n; ++i) {
            int ed = i + days[i];
            last = max(ed, last);
            while(!pq.empty() && pq.top().first<=i) pq.pop();
            if(apples[i]>0)
                pq.emplace(ed, apples[i]);
            
            if(!pq.empty()){
                auto tp = pq.top(); pq.pop();
                --tp.second;
                if(tp.second > 0){
                    pq.emplace(tp.first, tp.second);
                }
                ++ans;
            }
        }

        for(int i=n; i<=last;){
            while(!pq.empty() && pq.top().first<=i) pq.pop();
            if(pq.empty()) break;
            auto tp = pq.top(); pq.pop();
            int delta = min(tp.first-i, tp.second);
            i += delta;
            ans += delta;
        }
        return ans;
    }
};
