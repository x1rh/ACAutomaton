/*
反转一个链表，使用头插法，没要求使用原来的结点
*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        bool flag = false;
        ListNode* prev = NULL;
        while(pHead != NULL){
            ListNode* cur = new ListNode(pHead->val);
            cur->next = prev;
            pHead = pHead->next;
            prev = cur;
        }
        return prev;
    }
};