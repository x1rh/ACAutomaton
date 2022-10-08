class Solution {
public:
    struct Node{
        int to, di;
        Node(int to, int di):to(to), di(di){}
    };

    void dfs(TreeNode *root, map<int, vector<int>> &g){
        if(root){
            if(root->left){
                g[root->val].push_back(root->left->val);
                g[root->left->val].push_back(root->val);
                dfs(root->left, g);
            }   
            if(root->right){
                g[root->val].push_back(root->right->val);
                g[root->right->val].push_back(root->val);
                dfs(root->right, g);
            }

        }
    }

    void bfs(int st, int k, map<int, vector<int>> &g, vector<int> &ans){
        queue<Node> q;
        q.push(Node(st, 0));
        map<int, bool> vis;
        vis[st] = true;
        while(!q.empty()){
            Node fr = q.front(); q.pop();
            if(fr.di == k){
                ans.push_back(fr.to);
                continue;
            }
            for(int i=0; i<g[fr.to].size(); ++i){
                if(!vis[g[fr.to][i]]){
                    q.push(Node(g[fr.to][i], fr.di+1));
                    vis[g[fr.to][i]] = true;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int, vector<int>> g;
        dfs(root, g);
        vector<int> ans;
        bfs(target->val, k, g, ans);
        return ans;
    }
};