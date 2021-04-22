/*

这题需要想明白如何取最长无重复子串。
尺取法从左到右取逻辑上合理吗？答：合理，我觉得这并不显而易见，但没有一种好的证明方法
需要注意的点是，尺子移动后需要把之前的放在map中的值清除

*/

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        map<int, int> mp;
        int ans = 0;
        int len = 0;
        int clear = 0;
        for(int i=0; i<arr.size(); ++i){
            if(!mp[arr[i]]){
                mp[arr[i]] = i+1;
                len += 1;
            }
            else{
                if(len > ans){
                    ans = len;
                }
                len = i - (mp[arr[i]]-1);
                int tmp = mp[arr[i]]-1;
                for(int j=mp[arr[i]]-1; j>=clear; --j){
                    mp[arr[j]] = 0;
                }
                mp[arr[i]] = i+1;
                clear = tmp;
            }
        }
        return max(ans, len);
    }
};