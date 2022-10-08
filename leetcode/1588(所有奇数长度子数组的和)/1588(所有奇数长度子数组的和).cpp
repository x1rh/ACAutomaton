class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        for(int i=1; i<=n; i+=2){
            for(int j=0; j<n; ++j){
                if(j+i>n) break;
                for(int k=j; k<n&&k<j+i; ++k){
                    ans += arr[k];
                }
            }
        }
        return ans;
    }
};