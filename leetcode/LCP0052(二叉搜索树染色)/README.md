# 题目
[LCP 52. 二叉搜索树染色](https://leetcode-cn.com/problems/QO5KpG/)


# 题意


# 思路
中序遍历求出树上的所有节点（有序），然后由于节点值可能不连续，所以需要进行离散化。

离散化后，所有节点的值都小于等于10的五次方，所以可以用0x3f3f3f3f做为空标记。


```cpp
class Solution {
public:
    static const int maxn = 100000 + 100;
    int n, ans;
    int sumv[maxn<<2], setv[maxn<<2];
    vector<int> arr;

    void down(int rt, int len) {
        if(setv[rt] != 0x3f3f3f3f){
            setv[rt<<1] = setv[rt<<1|1] = setv[rt];
            sumv[rt<<1] = setv[rt] * (len-(len/2));
            sumv[rt<<1|1] = setv[rt] * (len/2);
            setv[rt] = 0x3f3f3f3f;
        }
    }

    void up(int rt) {
        sumv[rt] = sumv[rt<<1] + sumv[rt<<1|1];
    }

    void Set(int rt, int a, int b, int l, int r, int v) {
        if(a<=l && r<=b) {
            setv[rt] = v;
            sumv[rt] = (r-l+1)*v;
        } else {
            down(rt, r-l+1);
            int mid = (l+r)>>1;

            if(a<=mid) Set(rt<<1, a, b, l, mid, v);
            if(mid<b) Set(rt<<1|1, a, b, mid+1, r, v);

            up(rt);
        }
    }
    
    void dfs(TreeNode* root) {
        if(root) {
            dfs(root->left);
            arr.push_back(root->val);
            dfs(root->right);
        }
    }


    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        arr.clear();
        dfs(root);
        n = arr.size();

        memset(sumv, 0, sizeof(sumv));
        memset(setv, 0x3f, sizeof(setv));
        Set(1, 1, n, 1, n, 0); // 线段树初始化，实际上等价于setv[1] = 0

        for(auto &x : ops) {
            int l = lower_bound(arr.begin(), arr.end(), x[1]) - arr.begin() + 1;
            int r = lower_bound(arr.begin(), arr.end(), x[2]) - arr.begin() + 1;
            Set(1, l, r, 1, n, x[0]);
        }
        
        return sumv[1];
    }
};
```