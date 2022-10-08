class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mp;
        ListNode *p_a=headA, *p_b=headB, *ans=nullptr;
        while(p_a){
            mp[p_a] += 1;
            p_a = p_a->next;
        } 
        while(p_b){
            mp[p_b] += 1;
            if(mp[p_b] == 2){
                ans = p_b;
                break;
            }
            p_b = p_b->next;
        }
        return ans;
    }
};