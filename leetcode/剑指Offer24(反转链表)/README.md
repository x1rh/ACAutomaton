# 题目
`https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/`


# 思路
反转一个链表

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* retv = nullptr;
        while(head){
            auto nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};
```