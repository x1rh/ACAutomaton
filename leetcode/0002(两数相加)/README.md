# 题目
https://leetcode-cn.com/problems/add-two-numbers/


# 题意
求两个非负整数之和，每个数的数位存在链表的节点中，并逆置。

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 && l2){
            ListNode* head=nullptr, *prev=new ListNode(0), *curr=nullptr;
            int carry=0, x=0;
            while(l1 || l2){
                if(l1 && l2){
                    x = l1->val + l2->val + carry;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else if(l1){
                    x = l1->val + carry;
                    l1 = l1->next;
                }
                else if (l2){
                    x = l2->val + carry;
                    l2 = l2->next;
                }

                curr = new ListNode(x % 10);
                prev->next = curr;
                prev = curr;
                carry = x/ 10;
                if(!head) head = prev;
            }

            if(carry){
                prev->next = new ListNode(carry);
                prev = prev->next;
            }

            return head;
        }
        else if(l1) return l1;
        else if(l2) return l2;
        else return nullptr;
    }
};
```