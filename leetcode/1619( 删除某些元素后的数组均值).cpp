/*

由于保证了数组长度是20的倍数，所以这题十分简单
*/

class Solution {
public:
    double trimMean(vector<int>& arr) {
        double ans = 0;
        sort(arr.begin(), arr.end());
        int i = arr.size()/20;
        int j = arr.size()/20*19;
        for(; i<j; ++i){
            ans += arr[i];
        }
        return ans/(arr.size()/20*18*1.0);
    }
};