class Solution {
public:

    tuple<bool, int, int> intersect(int l1, int r1, int l2, int r2){
        if(r1 < l2) return {false, 0, 0};
        if(r2 < l1) return {false, 0, 0};
        if(l1<=l2 && l2<=r1 && r1<=r2){
            return {true, l2, r1};
        }
        if(l2<=l1 && l1<=r2 && r2<=r1){
            return {true, l1, r2};
        }
        if(l2<=l1 && r1<=r2) return {true, l1, r1};
        if(l1<=l2 && r2<=r1) return {true, l2, r2};
        return {false, 0, 0};
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans;
        for(int i=0; i<firstList.size(); ++i){
            int l1 = firstList[i][0];
            int r1 = firstList[i][1];
            for(int j=0; j<secondList.size(); ++j){
                int l2 = secondList[j][0];
                int r2 = secondList[j][1];
                auto [flag, x, y] = intersect(l1, r1, l2, r2);
                if(flag){
                    ans.push_back({x, y});
                }
            }
        }
        return ans;
    }
};