/*

排序两次
先按数值大小排序

然后记录在其前面的有多少位数，注意重复元素算一种情况，找到最左边即可

然后再按原来的下标排序回来


看了题解后发现第二次排序多此一举了。。。
*/

class Solution {
public:
    struct Node{
        int val;
        int idx;
        int ans;
        Node(){}
        Node(int val, int idx):val(val), idx(idx){}
        bool operator<(const Node& rhs){
            if(this->val < rhs.val){
                return true;
            }
            else if(this->val == rhs.val){
                return this->idx < rhs.idx;
            }
            else{
                return false;
            }
        }
    };

    static bool cmp(const Node& lhs, const Node& rhs){
        return lhs.idx < rhs.idx;
    }

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<Node> vec(nums.size());
        for(int i=0; i<nums.size(); ++i){
            vec[i].idx = i;
            vec[i].val = nums[i];
        }
        sort(vec.begin(), vec.end());

        vector<int> ans(nums.size(), 0);
        for(int i=0; i<vec.size(); ++i){
            int j = i-1;
            for(; j>=0 && vec[j].val==vec[i].val; --j);
            vec[i].ans = ++j;
        }

        sort(vec.begin(), vec.end(), cmp);
        
        for(int i=0; i<vec.size(); ++i){
            ans[i] = vec[i].ans;
        }
        return ans;
    }
};