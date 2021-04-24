/*

记A=arr
记A_i表示以A[i]为结尾的最长上升子序列(包含A[i]在内)

设数组lis表示：
(1) len(lis)表示从左往右遍历到下标i时的所有上升子序列的最大长度
(2) lis中可以获得到A_i, 但lis并不一定等于A_i
(3) lis用于快速求A_i
(4) lis是严格非递减的

lis的更新：
当A[i] > lis.back()时, lis.push_back(A[i])
否则在lis中二分查找，找到第一个大于A[i]的位置x，并令lis[x] = A[i].

明白lis的更新策略后便可轻易理解上面lis定义中的第(2), (3)点

len数组：
设数组len[i]表示A_i的长度。在更新lis的过程中可以求得数组len
隐含条件：len[i]对应着A[i]


最小字典序：
对于len数组，假设len数组为[1, 2, 3, 1, 2, 3]，则可知：
(1)最长上升子序列长度为3
(2)记第一个3所表示的上升子序列为X，第二个3所表示的上升子序列为Y，
则Y的字典序一定小于X的字典序，这么考虑是因为, 前提假设len(X)=len(Y)=3
若X的字典序小于Y的字典序，则Y的长度len(Y)>3, 与假设矛盾，故X的字典序大于Y的字典序

如何取最小字典序：
设len=[1, 2, 3, 1, 2, 3]，则最长上升子序列的长度L=3，
L从3递减至0，每递减1，取len数组中最右边的数所对应的A[i]

*/

class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */


    vector<int> LIS(vector<int>& arr) {

        int sz = arr.size();
        vector<int> ans;

        if(sz==0) return ans;

        vector<int> lis(sz);
        vector<int> len(sz);

        lis[0] = arr[0];
        len[0] = 1;
        int idx = 0;
        for(int i=1; i<sz; ++i){
            if(arr[i]>=lis[idx]){
                lis[++idx] = arr[i];
                len[i] = idx + 1;
            }
            else{
                int insert = upper_bound(lis.begin(), lis.begin()+idx, arr[i]) - lis.begin();
                if(insert<sz && lis[insert]==arr[i]) ++insert;
                lis[insert] = arr[i];
                len[i] = insert+1;
            }
        }
        for(int i=sz-1; i>=0; --i){
            if(len[i] == idx+1){
                ans.push_back(arr[i]);
                --idx;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};