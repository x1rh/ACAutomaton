# 题目
[1380. 矩阵中的幸运数](https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/)


# 题意
求矩阵中所有的幸运数，幸运数的定义是当前行最小，当前列最大。



# 思路
模拟即可，时间复杂度O(mn(m+n))

cpp
```cpp
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
```

go
```go
func luckyNumbers (matrix [][]int) []int {
    m := len(matrix)
    n := len(matrix[0])

    var ans []int 

    for i:=0; i<m; i++ {
        for j:=0; j<n; j++ {

            flag := false 
            for k:=0; k<n; k++ {
                if k == j {
                    continue 
                }
                if matrix[i][k] > matrix[i][j] {
                    continue
                } else {
                    flag = true 
                    break
                }
            }        

            if flag {
                continue
            }

            for k:=0; k<m; k++ {
                if i == k {
                    continue
                }
                if matrix[k][j] < matrix[i][j] {
                    continue;
                } else {
                    flag = true;
                    break;
                }
            }
            if flag {
                continue;
            }
            ans = append(ans, matrix[i][j])
        }
    }
    return ans
}
```