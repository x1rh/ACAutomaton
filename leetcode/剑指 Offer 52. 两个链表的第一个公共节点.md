# 题意
[题目链接](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)

寻找两个链表的第一个交点，若不存在则返回空指针

# 解法1
存`map<ListNode*, int>`
空间复杂度O(n), 时间复杂度O(n+m)

```cpp
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
```


# 解法2
将两个链表串成环（遍历到末尾时从另一个链表头重新开始）

设A链表由a+c组成，B链表由b+c组成，它们串成环，意味着，大家同时走a+b+c后一定会相遇，路径是固定的：
A为：a -> c -> b
B为：b -> c -> a 

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }

        ListNode *pa=headA, *pb=headB;
        while(pa != pb){
            pa = pa==nullptr?headB:pa->next;
            pb = pb==nullptr?headA:pb->next;
        }
        return pa;
    }
};
```
这个设计比较巧妙：
51行设计成`pa = pa==nullptr?headB:pa->next`而不是`pa = pa->next==nullptr?headB:pa->next`
若两个链表相交，则49行到54行的逻辑一定正确。

现在考虑两个不链表相交的情况：
- 若两个链表长度相等（为m），则执行49到53行，遍历m次后，pa和pb都为nullptr，退出循环
- 若两个链表长度不等（为m和n），则遍历m+n次后，pa和pb都等于nullptr，退出循环
即思想是，插入一个nullptr为相交节点


