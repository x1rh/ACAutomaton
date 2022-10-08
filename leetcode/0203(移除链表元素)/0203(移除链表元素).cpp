class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* nh = head;
        while(nh && nh->val==val){
            ListNode* tmp = nh;
            nh = nh->next;
            delete tmp;
        }
        ListNode* ans = nh;
        ListNode* prev = nullptr;
        while(nh){

            if(nh->val == val){
                ListNode* del = nh;
                nh = nh->next;
                delete del;
                prev->next = nh;
            }
            else{
                prev = nh;
                nh = nh->next;
            }
        }
        return ans;
    }
};