/*
凹槽分为三种，第一种是左挡板比右挡板高，第二种是左挡板比右挡板低，第三种是左右挡板同样高

第一次遍历，从左往右，计算左边挡板高度小于等于右边挡板高度的情况，即包含上面定义的第一、三种情况。
第二次遍历，从右往左，计算第一种情况（相当于从左往右遍历处理第二种凹槽）
两次遍历把所有情况都包含。
左右挡板同样高这种情形容易重复计算，需要注意。

逻辑的严密性：
1.为什么第二次遍历从右往左？
因为低挡板决定凹槽容量，我们总是假设当前挡板是低的那一端，找到一个比它高的挡板，一旦找到，则凹槽容量确定。
而如果我们假设当前挡板是高的一端，那么后续可能有多个低挡板与之匹配，且这十分难计算。

2.为什么这样遍历能把所有情况包含，而且既没有遗漏，也没有重复计算？
因为三种凹槽是互不相容的，这才是算法成立的逻辑前提。每次遍历我们都找到目标的凹槽，取并集即可。


*/

class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    
    long long maxWater(vector<int>& arr) {
        if(arr.size()<=2)return 0;
        long long ans=0, temp=0;
        int le = 0;
        for(int i=1;i<arr.size(); ++i){
            if(arr[i] < arr[le]){
                temp += arr[le] - arr[i];
            }
            else{
                le = i;
                ans += temp;
                temp = 0;
            }
        }
        
        temp = 0;
        le = arr.size()-1;
        for(int i=arr.size()-2; i>=0; --i){
            if(arr[le] > arr[i]){
                temp += arr[le] - arr[i];
            }
            else if(arr[le] == arr[i]){ 
                le = i;
                temp = 0;
            }
            else{
                le = i;
                ans += temp;
                temp = 0;
            }
        }
        
        return ans;
    }
};