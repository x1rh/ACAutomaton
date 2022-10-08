/*

这里我采用了求 |arr1[i] - arr2[j]| <= d的个数，然后用arr1.size()减去


 
*/



class Solution {
public:
    bool in_it(int l, int r, int mid){
        return l<=mid && mid<=r;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;
        for(int i=0; i<arr1.size(); ++i){
            int idx = lower_bound(arr2.begin(), arr2.end(), -d+arr1[i]) - arr2.begin();
            int idy = lower_bound(arr2.begin(), arr2.end(),  d+arr1[i]) - arr2.begin();
            if(idx == arr2.size()){
                --idx;
            }
            if(idy == arr2.size()){
                --idy;
            }
            if( idx <= idy ){
                if(
                    in_it(-d+arr1[i], d+arr1[i], arr2[idx]) ||
                    in_it(-d+arr1[i], d+arr1[i], arr2[idy])
                )
                    // cout<<arr[idx]<<" "<<arr[idy]<<endl;
                    ++ans;
            }
        }
        return arr1.size() - ans;
    }
};