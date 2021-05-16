class Solution {
public:
    struct Node{
        int v;
        int i;
        int j;
        Node(int v, int i, int j):v(v), i(i), j(j){}
    };

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<Node> arr(matrix.size(), Node(-1, -1, -1));
        for(int i=0; i<matrix.size(); ++i){
            int inf = 0x3f3f3f3f;
            int ii=-1, jj=-1;
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j] < inf){
                    inf = matrix[i][j];
                    ii = i;
                    jj = j;
                }
            }
            arr[i].v = inf;
            arr[i].i = ii;
            arr[i].j = jj;
        }

        vector<int> ans;
        for(int i=0; i<arr.size(); ++i){
            bool flag = true;
            for(int j=0; j<matrix.size(); ++j){
                if(matrix[j][arr[i].j] > arr[i].v){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.emplace_back(arr[i].v);
        }
        return ans;
    }
};