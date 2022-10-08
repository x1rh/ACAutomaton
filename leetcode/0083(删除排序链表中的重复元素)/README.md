# 题目
`https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/`

# 思路
删除链表中重复的元素，例如[1, 1, 2, 3] -> [1, 2, 3]   
注意事项：
    - 只有prev和now值不等时，才能移动prev，才能将prev->next进行更新
    - prev的next一定要置nullptr



```cpp
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
```