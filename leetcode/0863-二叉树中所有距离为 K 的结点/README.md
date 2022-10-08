# 题目
`https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/`

# 思路
求距离树节点target距离为k的节点，这些节点只可能在target的左下、右下、上边（祖先）

一种通用简单的方法是，将树转换为无向图，然后跑bfs，把所有距离为k的点记录即可。

```cpp
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
```


官方题解的思路是从target往上建立一颗树