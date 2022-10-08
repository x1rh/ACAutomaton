/*
一定要明确二元组排序时，当第一个数值相等时，第二个数如何排序
行号更新问题
*/

class Solution {
public:
    struct Node{
        int val;
        int row;
        Node(){}
        Node(int val, int row):val(val), row(row){}
        bool operator<(const Node& rhs){
            if(this->val < rhs.val){
                return true;
            }
            else{
                if(this->val == rhs.val){
                    return this->row < rhs.row;
                }
                else{
                    return false;
                }
            }
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Node> v(mat.size(), {0, -1});
        for(int i=0; i<mat.size(); ++i){
            v[i].row = i;
            for(int j=0; j<mat[i].size(); ++j){
                if(mat[i][j] == 1){
                    v[i].val += 1;
                }
                else{
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        vector<int> ans(k, 0);
        for(int i=0; i<k; ++i){
            ans[i] = v[i].row;
        }
        return ans;
    }
};