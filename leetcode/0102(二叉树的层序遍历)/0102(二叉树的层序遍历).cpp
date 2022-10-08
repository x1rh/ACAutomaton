class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode t(0x3f3f3f3f);
        TreeNode* pivot = &t;
        q.push(pivot);

        queue<TreeNode*> ta;
        while(!q.empty()){
            auto fr = q.front(); q.pop();
            if(fr->val == 0x3f3f3f3f){
                vector<int> v(ta.size(), 0);
                for(int i=0; !ta.empty(); ++i){
                    v[i] = ta.front()->val;
                    ta.pop();
                }
                ans.emplace_back(v);
                if(!q.empty()) q.push(pivot);
            }
            else{
                ta.push(fr);
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
        }
        return ans;
    }
};