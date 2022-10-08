# 题目
`https://leetcode-cn.com/problems/remove-linked-list-elements/`


# 思路
删除链表中值为x的元素  

注意事项：
- 先把头结点处理好（如果头结点以x开头，需要删除直到头不为x为止）
- prev指针的移动和prev->next的更新

```cpp
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
```