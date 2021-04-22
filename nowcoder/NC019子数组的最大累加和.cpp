/*

最大连续子序列和      时间O(n), 空间O(1)

定义：dp[i]表示连续的从下标x到下标i的数的和，x<i 
下面说明递推的严谨性:


(1)如果A[i]>0, 若dp[i-1]<0 则 dp[i] = A[i]，因为我们可以从下标i重新开始，而不是加上前面的负数和；
若dp[i-1]>0 显然dp[i] = dp[i-1] + A[i];
(2)如果A[i]<0, 若dp[i-1]<0 则 dp[i] = A[i]，理由同上，重新从i开始累加，dp[i]可以更大；
如果dp[i-1]>0, 虽然dp[i] = dp[i-1] + A[i] 显得比dp[i-1]小了，但对下标i来说，dp[i]=dp[i-1]+A[i]是最大的

初始化问题：

*/

class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        vector<int> dp = arr;
        for(int i=1; i<arr.size(); ++i){
            dp[i] = max(arr[i], dp[i-1]+arr[i]);
        }
        int ans = arr[0];
        for(int i=1; i<dp.size(); ++i){
            if(dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};