/*
这题我用map做的原因是，题目没有说清楚两个链表相交后是变为一条链表，还是继续是两条链表
*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        map<ListNode*, int> mp;
        while(pHead1){
            if(mp[pHead1]==1) return pHead1;
            else mp[pHead1] += 1;
            pHead1 = pHead1->next;
        }
        while(pHead2){
            if(mp[pHead2]==1) return pHead2;
            else mp[pHead2] += 1;
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};