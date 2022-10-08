class Solution {
public:
    bool is_odd(int x){
        return x & 1; 
    }

    bool is_even(int x){
        return !(x & 1);
    }

    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int level = 0;
        TreeNode* last = nullptr;

        while(!q.empty()){
            TreeNode* fr = q.front(); q.pop();
            if(fr){
                if(is_odd(level)){
                    if(is_odd(fr->val)) return false;
                    if(last && (last->val <= fr->val)) return false;
                }
                else{
                    if(is_even(fr->val)) return false;
                    if(last && (last->val >= fr->val)) return false;
                }
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
            else{
                if(last) {
                    q.push(nullptr);
                }
                ++level;
            }
            last = fr;
        }
        return true;
    }
};
