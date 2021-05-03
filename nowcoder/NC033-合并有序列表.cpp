/*
题意：
合并两个有序列表

解法一：
模拟，
当l1->val < l2->val时，寻找l1中第一个大于l2->val的节点x，
用指针prev1记录节点x的前一个节点，将prev1的next指针指向l2，将l1指针指向节点x;

当l2->val < l2->val时，寻找l2中第一个大于l1->val的节点y，
用指针prev2记录节点y的前一个节点，将prev2的next指针指向l1，将l2指针指向节点y;

以上逻辑是严密的，两条链，断一次链接一次

解法二：
递归，
想象每次从两个链表x和y中选出小的那个节点a，假设a在链表x中，则将x链表指针后移
递归执行上述过程，每次递归产生一个当前最小的节点返回给当前函数，并将其与之前的结果串联即可
*/


##########################################################################
######                        解法一                          ############
##########################################################################
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev1=NULL, *prev2=NULL;
        ListNode *ans = NULL;
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1==NULL && l2!=NULL){
            return l2;
        }
        else if(l1!=NULL && l2==NULL){
            return l1;
        }
        else{
            if(l1->val < l2->val) ans = l1;
            else ans = l2;
        }

        while(l1 && l2){
            if(l1->val < l2->val){
                while(l1 && l1->val <= l2->val) {
                    prev1 = l1;
                    l1 = l1->next;
                }
                prev1->next = l2;
            }
            else{
                while(l2 && l2->val <= l1->val){
                    prev2 = l2;
                    l2 = l2->next;
                }
                prev2->next = l1;
            }
        }
        return ans;
    }
};


##########################################################################
######                        解法二                          ############
##########################################################################

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL;
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1==NULL && l2!=NULL){
            return l2;
        }
        else if(l1!=NULL && l2==NULL){
            return l1;
        }
        else{
            if(l1->val < l2->val){
                ans = l1;
                ans->next = mergeTwoLists(l1->next, l2);
            }
            else{
                ans = l2;
                ans->next = mergeTwoLists(l1, l2->next);
            }
        }
        return ans;
    }
};