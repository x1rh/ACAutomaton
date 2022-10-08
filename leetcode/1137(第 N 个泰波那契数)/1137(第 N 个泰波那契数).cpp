class Solution {
public:
    int tribonacci(int n) {
        vector<int> tr = {0, 1, 1};
        for(int i=3; i<=37; ++i){
            tr.push_back(tr[i-1] + tr[i-2] + tr[i-3]);
        }
        return tr[n];
    }
    
};