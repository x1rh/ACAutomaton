/*

二叉树层序遍历，将每一层按要求输出，解题思路为给每一层添加一个哨兵。
初始化时，往队列放入树根、哨兵，当读到哨兵时意味着一层遍历完成，若此时队列非空，
则继续往队列末尾添加哨兵。

*/

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode> q;
        vector<vector<int> > ans;
        
        if(root==NULL) return ans;
        
        vector<int> cur;
        bool flag = true;
        const int inf = 0x3f3f3f3f;
        TreeNode pivot(inf);
        q.push(*root);
        q.push(pivot);

        while(!q.empty()){
            TreeNode fr = q.front();
            q.pop();
            if(fr.val == inf){
                if(flag){
                    ans.push_back(cur);
                    cur.clear();
                }
                else{
                    reverse(cur.begin(), cur.end());
                    ans.push_back(cur);
                    cur.clear();
                }
                if(!q.empty()) q.push(pivot);
                flag = !flag;
            }
            else{
                cur.push_back(fr.val);
                if(fr.left != NULL) q.push(*fr.left);
                if(fr.right != NULL) q.push(*fr.right);
            }
        }
        return ans;
    }
};
