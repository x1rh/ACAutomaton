# 题目
`https://leetcode-cn.com/problems/reverse-linked-list/`


# 思路
逆置一个链表    
方法：头插法逆转  


```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while(head){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
```