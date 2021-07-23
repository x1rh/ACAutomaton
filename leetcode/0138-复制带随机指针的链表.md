# 思路
由于有随机指针，所以无法直接拷贝，先生成链表，再给random指针赋值

这里利用了4个map做映射，达成O(n)时间复杂度的复制

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node *curr = head;
        Node *prev = nullptr;
        Node *copy_head = nullptr;
        map<int, Node*> idx2ptr;
        map<Node*, int> ptr2idx;
        map<int, int> idx2idx;
        map<int, Node*> new_idx2ptr;
        int idx = 0;
        while(curr){
            Node *temp = new Node(curr->val);
            if(prev != nullptr){
                prev->next = temp;
            }
            else{
                copy_head = temp;
            }
            prev = temp;
            idx2ptr[idx] = curr;
            new_idx2ptr[idx] = temp;
            ptr2idx[curr] = idx;
            ++idx;
            curr = curr->next;
        }

        curr = head;
        idx = 0;
        while(curr){
            if(idx2ptr[idx]->random==nullptr)
                idx2idx[idx] = -1;
            else
                idx2idx[idx] = ptr2idx[idx2ptr[idx]->random];
            curr = curr->next;
            ++idx;
        }

        curr = copy_head;
        idx = 0;
        while(curr){
            if(idx2idx[idx]!=-1){
                curr->random = new_idx2ptr[idx2idx[idx]];
            }
             
            curr = curr->next;
            ++idx;
        }

        return copy_head;
        
    }
};

```