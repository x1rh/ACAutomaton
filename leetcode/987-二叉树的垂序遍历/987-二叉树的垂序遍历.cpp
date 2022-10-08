class Solution {
public:
    struct Node{
        int v, x, y;
        Node(int v, int x, int y):v(v), x(x), y(y){}
        bool operator<(const Node &rhs)const{
            if(this->x < rhs.x){
                return true;
            }
            else if(this->x == rhs.x){
                return this->v < rhs.v;
            }
            else return false;
        }
    };

    void dfs(TreeNode *root, map<int, priority_queue<Node>> &mp, int x, int y){
        if(root){
            mp[y].push(Node(root->val, x, y));
            if(root->left) dfs(root->left, mp, x+1, y-1);
            if(root->right) dfs(root->right, mp, x+1, y+1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, priority_queue<Node>> mp;
        dfs(root, mp, 0, 0);
        vector<vector<int>> ans;
        for(auto &[k, v] : mp){
            vector<int> tmp(v.size(), 0);
            int idx = v.size()-1;
            while(!v.empty()){
                tmp[idx--] = v.top().v; v.pop();
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};