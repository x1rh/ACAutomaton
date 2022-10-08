class Solution {
public:

    vector<int> pathInZigZagTree(int label) {
        vector<pair<int, int>> itvl;
        int depth = -1;
        itvl.emplace_back(pair<int, int>(0, 0));   // 仅仅用于填充
        for(int i=1; i<=20; ++i){
            int l = pow(2, i-1);
            int r = pow(2, i)-1;
            if(l<=label && label<=r){
                depth = i;
            }
            if(i&1)
                itvl.emplace_back(pair<int, int>(l, r));
            else
                itvl.emplace_back(pair<int, int>(r, l));
        }
        vector<int> ans;
        int curr = label;
        ans.push_back(label);
        while(depth>1){
            int nxt = floor(curr/2);
            if(depth & 1){
                ans.push_back(itvl[depth-1].first-(nxt-itvl[depth-1].second));
            }
            else{
                ans.push_back(itvl[depth-1].first+itvl[depth-1].second - nxt);
            }
            curr = ans.back();
            --depth;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};