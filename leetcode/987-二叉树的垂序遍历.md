# 题目
`https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/`

# 思路
最多1000个节点，意味着二叉树最高10层，记节点数为N。我们遍历一遍用一个`map<int, priority_queue<Node>>`存下来即可，key为列号。

用pq可以使得时间复杂度为`log2 M`， 其中M为对应列的深度，最坏M退化为N。

遍历的时间复杂度为O(NlogN) 包含维护map的时间。

输出答案时的时间复杂度也为O(NlogN)。

按理说用vector替代pq，也不会T。


```cpp
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
```



官方题解利用特性进行解题，利用了tuple，3元组排序完事。