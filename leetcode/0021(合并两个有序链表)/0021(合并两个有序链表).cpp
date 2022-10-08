class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while(l1 && l2){
            if(l1->val < l2->val){
                if(!head) head = l1;
                if(!prev){
                    prev = l1;
                    l1 = l1->next;
                }
                else{
                    prev->next = l1;
                    prev = l1;
                    l1 = l1->next;
                }
                
            }
            else{
                if(!head) head = l2;
                if(!prev){
                    prev = l2;
                    l2 = l2->next;
                }
                else{
                    prev->next = l2;
                    prev = l2;
                    l2 = l2->next;
                }
            }
        }
        if(l1) prev->next = l1;
        if(l2) prev->next = l2;
        return head;
    }
};