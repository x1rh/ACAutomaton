class Solution {
public:

    Node* dfs(Node* head){
        if(head){
            auto next = head->next;
            if(head->child){
                auto tail = dfs(head->child);
                head->next = head->child;
                head->child->prev = head;
                
                head->child = nullptr;
                
                tail->next = next;
                if(next) next->prev = tail;
                return dfs(tail);   // 这里必须dfs，以维持dfs的递推性，tail并不是逻辑上严谨的tail
            }
            if(head->next){
                return dfs(head->next);
            }
            if(head->child==nullptr){
                return head;
            }
        }
        return nullptr;
    }

    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};
