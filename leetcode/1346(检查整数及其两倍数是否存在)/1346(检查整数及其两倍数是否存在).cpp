/*

1. 特殊数字0
2. 重复0
3. upper_bound() 的可能范围是[0, size()]，不要觉得取不到下标0

*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool flag = false;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); ++i){
            int it = upper_bound(arr.begin(), arr.end(), arr[i]*2) - arr.begin();
            if(0<=it-1 && it-1<=arr.size() && it-1!=i && arr[it-1]==arr[i]*2){
                flag = true;
                break;
            }
        }
        return flag;
    }
};