class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mx(prices.size(), 0);
        mx[0] = prices[0];
        int mi = mx[0];
        for(int i=1; i<prices.size(); ++i){
            if(mi > prices[i]) mi = prices[i];
            mx[i] = mi;
        } 

        int ans = 0;
        for(int i=0; i<mx.size(); ++i){
            int cur = prices[i] - mx[i];
            if(ans < cur) ans = cur;
        }
        return ans;
    }
};