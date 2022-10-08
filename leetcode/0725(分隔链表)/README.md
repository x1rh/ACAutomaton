# 题目
`https://leetcode-cn.com/problems/split-linked-list-in-parts/`

# 思路
将n个元素分为k组，若元素不足，则剩余组比之前的组少一个元素。

我这里用一个数组记录每组元素个数。

```cpp
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto th = head;
        int len = 0;
        while(th){
            ++len;
            th = th->next;
        }
        int d = len / k;
        vector<int> cnt(k, d);
        int md = len % k;
        for(int i=0; i<md; ++i) cnt[i] += 1;
        vector<ListNode*> ans;
        ListNode* prev = nullptr;
        th = head;

        for(int i=0; i<cnt.size(); ++i){
            if(th) ans.push_back(th);
            else ans.push_back(nullptr);
            for(int j=0; j<cnt[i] && th; ++j){
                prev = th;
                th = th->next;
            }
            if(ans.back()) prev->next = nullptr;
        }
        return ans;
    }
};
```