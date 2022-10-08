class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(head && !head->next) return false;
        if(head && head->next && !head->next->next) return false;
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(slow && fast){
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next;
            if(!fast) return false;
            fast = fast->next;
        }
        return false;
    }
};