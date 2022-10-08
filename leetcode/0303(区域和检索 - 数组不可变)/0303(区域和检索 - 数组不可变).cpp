class NumArray {
public:
    vector<int> v;
    vector<int> pre;

    void init(){
        pre.assign(v.size()+1, 0);
        pre[0] = 0;
        for(int i=1; i<=v.size(); ++i){
            pre[i] = pre[i-1] + v[i-1];
        }
    }


    NumArray(vector<int>& nums) {
        v.swap(nums);
        init();

    }
    
    int sumRange(int left, int right) {
        return pre[right+1] - pre[left];
    }
};