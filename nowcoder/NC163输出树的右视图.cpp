/*

先从前序、中序构建二叉树，从前序获得当前根节点，根节点将中序序列划分为两部分A和B，
利用A和B的长度分别对前序序列进行划分，以此递归构建二叉树；

构建完成后可以进行先序遍历和后序遍历进行验证

求右视图，右视图的求法是树的分层遍历，记录每层的最右边的数。

*/

class Solution {
public:
    struct Node{
        int val;
        struct Node *left, *right;
        Node(int val):val(val), left(nullptr), right(nullptr){}
    };
    
    Node* build(vector<int>& xianxu, int st, int ed, vector<int>& zhongxu, int le, int ri){
        if(st>ed || le>ri) return nullptr;
        int idx = -1;
        for(int i=le; i<=ri; ++i){
            if(zhongxu[i] == xianxu[st]) {
                idx = i;
                break;
            }
        }
        int len = idx - le;
        Node *root = new Node(zhongxu[idx]);
        root->left = build(xianxu, st+1, st+len, zhongxu, le, idx-1);
        root->right = build(xianxu, st+len+1, ed, zhongxu, idx+1, ri);
        return root;
    }
    
    void preOrder(Node* root){
        if(root){
            cout<<root->val<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    
    void inOrder(Node* root){
        if(root){
            inOrder(root->left);
            cout<<root->val<<" ";
            inOrder(root->right);
        }
    }
    
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        vector<int> ans;
        if(xianxu.size()==0) return ans;
        
        Node* root = build(xianxu, 0, xianxu.size()-1, zhongxu, 0, zhongxu.size()-1);
//         preOrder(root); cout<<endl;
//         inOrder(root); cout<<endl;
        const int inf = 0x3f3f3f3f;
        queue<Node> q;
        Node pivot(inf);
        q.push(*root);
        q.push(pivot);
        int prev = inf;
        
        while(!q.empty()){
            Node fr = q.front();
            q.pop();
            if(fr.val == inf){
                ans.push_back(prev);
                if(!q.empty()) q.push(pivot);
            }
            else{
                prev = fr.val;
                if(fr.left) q.push(*fr.left);
                if(fr.right) q.push(*fr.right);
            }
            
        }
        return ans;
    }
};