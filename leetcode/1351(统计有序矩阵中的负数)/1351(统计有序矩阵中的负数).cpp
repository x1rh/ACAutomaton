/*
方法一，直接暴力
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(grid[i][j] < 0) ++cnt;
            }
        }
        return cnt;
    }
};

/*
方法二, 每一行做二分查找，复杂度为nlogm
*/

/*

方法三， O(n+m)
基于以下性质：
设
第i行，从左往右第一个负数下标为pos_i
第i+1行，从左往右第一个负数下标为pos_j
则pos_j在闭区间[0, pos_i]内

即pos_i是非递增的（下面代码中的len必定合理，有负数必更新）
*/


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int len = grid[0].size()-1;
        int ans = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<=len; ++j){
                if(grid[i][j] < 0){
                    ans += grid[i].size() - j;
                    len = j;
                    break;
                }
            }
        }
        return ans;
    }
};
