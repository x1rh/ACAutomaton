class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head){
        ListNode *prev= nullptr, *temp=head;
        while(head) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        ListNode *head=nullptr, *prev=nullptr, *curr=nullptr;
        int carry = 0;
        while(head1 && head2){
            int val = (carry + head1->val + head2->val) % 10;
            carry = (head1->val + head2->val + carry) / 10;
            curr = new ListNode(val);
            //cout<<val<<endl;
            if(prev) {
                prev->next = curr;
            }
            else{
                head = curr;    
            }
            prev = curr;
            head1 = head1->next;
            head2 = head2->next;
        }
        ListNode *left = nullptr;
        if(head1) left=head1;
        else if(head2) left=head2;
        while(left){
            int val = (left->val + carry) % 10;
            carry = (left->val + carry) / 10;
            curr = new ListNode(val);
            prev->next = curr;
            prev = curr;
            left = left->next;
            //cout<<val<<endl;
        }
        if(carry){
            curr = new ListNode(carry);
            prev->next = curr;
            prev = curr;
        }
        head = reverseList(head);
        return head;
    }
};