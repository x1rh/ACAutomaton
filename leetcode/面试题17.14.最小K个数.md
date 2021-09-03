# 题目
`https://leetcode-cn.com/problems/smallest-k-lcci/`


# 思路

解法1：排序+取前k个数
```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};
```


解法2： 维护一个k个元素的大顶堆，当元素小于大顶堆的最大值时，将最大值出栈，将当前值加入堆
```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if(k==0) return ans;
        priority_queue<int> pq;
        for(int i=0; i<arr.size(); ++i){
            if(i<k) pq.push(arr[i]);
            else{
                if(arr[i] < pq.top()){
                    pq.push(arr[i]);
                    pq.pop();
                }
            }
        }
        for(int i=k-1; i>=0; --i){
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;
    }
};
```