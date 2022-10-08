# 题目
`https://leetcode-cn.com/problems/set-matrix-zeroes/`


# 思路
对含有0的那一行和那一列全部置为0  
要求使用O(1)的空间  

使用将被置为0的行用来记录信息，从而达到空间复杂度O(1)的要求

置0策略为：
1. 找到第一个0，将其所在的行x用于存放数据。

2. 逐行逐列遍历，遇到0则将这一行置为0，置0之前，对本行后续列中存在的0进行记忆（不重复记忆）

3. 将记录的列进行置0（但行x不置0）

4. 置行x全部为0


```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zi=-1, zj=-1;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j] == 0){
                    zi = i;
                    zj = j;
                    break;
                }
            }
            if(zi!=-1) break;
        }

        zj = -1;
        if(zi==-1 && zj==-1) return;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[i].size(); ++j){
                if(matrix[i][j] == 0){
                    for(int k=0; k<matrix[i].size(); ++k){
                        if(matrix[i][k]==0){
                            bool flag = false;
                            for(int g=0; g<=zj; ++g){
                                if(matrix[zi][g]==k){
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag) matrix[zi][++zj] = k;
                        }
                        if(zi!=i) matrix[i][k] = 0;
                    }
                    
                    break;
                }
            }
        }


        for(int i=0; i<=zj; ++i){
            for(int j=0; j<matrix.size(); ++j){
                if(j == zi) continue;
                matrix[j][ matrix[zi][i] ] = 0;
            }
        }

        for(int i=0; i<matrix[0].size(); ++i){
            matrix[zi][i] = 0;
        }
    }
};
```
