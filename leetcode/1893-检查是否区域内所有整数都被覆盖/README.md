# 思路
先排序，然后合并区间，然后遍历判断即可



```cpp
class Solution {
public:
    static bool cmp(const vector<int> &lhs, const vector<int> &rhs){
        if(lhs[0] < rhs[0]) return true;
        else if(lhs[0] == rhs[0]){
            return lhs[1] < rhs[1];
        }
        else return false;
    }

    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), cmp);
        vector<pair<int, int>> vec;
        vec.clear();
        if(ranges.size() == 0) return false;
        int prev = ranges[0][1];
        vec.push_back(make_pair(ranges[0][0], ranges[0][1]));
        for(int i=1; i<ranges.size(); ++i){
            if(ranges[i][0]-1 <= prev){
                if(ranges[i][1] > prev)
                    prev = ranges[i][1];
            }
            else{
                vec.back().second = prev;
                prev = ranges[i][1];
                vec.push_back(make_pair(ranges[i][0], ranges[i][1]));
            }
        }
        vec.back().second = prev;

        for(int i=0; i<vec.size(); ++i){
            if(vec[i].first<=left && right<=vec[i].second){
                return true;
            }
        }
        return false;
    }
};
```