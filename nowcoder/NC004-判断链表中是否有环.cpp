/*
方法一：染色，若遇到被染的颜色则认为是有环
方法二：快慢指针，一个指针走一步，另一个走两步，若有环，则他们终究会走到一起，若无环，则快指针先到达NULL
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int pivot = 0x3f3f3f3f;
        while(head){
            if(head->val == pivot){
                return true;
            }
            head->val = pivot;
            head = head->next;
        }
        return false;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        while(fast){
            head = head->next;
            fast = fast->next;
         
            if(fast==NULL) return false;
            else fast = fast->next;
            if(head == fast) return true;
        }
        return false;
    }
};