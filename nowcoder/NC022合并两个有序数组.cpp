/*

这题写起来特别烦
大体思路特别简单，就是用i、j两个指针，当A[i] > B[j]时，A数组下标大于等于i的后移一位，把B[j]放到A[i]
主要是i不好定界，只好改用left来标记原A数组中还剩下有多少个元素。

*/


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=0, j=0, left=m;
        while(left>0 && j<n){
            if(A[i]<=B[j]){
                ++i;
                --left;
            }
            else{
                int k = i+left;
                while(k>i){
                    A[k] = A[k-1];
                    --k;
                }
                A[i] = B[j];
                ++i;
                ++j;

            }
        }
        while(j<n){
            A[i] = B[j];
            ++i;
            ++j;
        }
    }
};
