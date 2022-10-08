class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans=head, *prev=nullptr;   
        while(head){
            if(prev){
                if(prev->val == head->val){
                    ListNode* del = head;
                    head = head->next;
                    delete del;
                    prev->next = nullptr;
                }
                else{
                    prev->next = head;
                    prev = head;
                    head = head->next;
                }
                
            }
            else{
                prev = head;
                head = head->next;
            }
        }
        return ans;
    }
};