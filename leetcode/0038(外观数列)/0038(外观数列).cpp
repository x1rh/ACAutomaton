class Solution {
public:
    string countAndSay(int n) {
        vector<string> vec = {"1", "11", "21", "1211", "111221"};
        if(n<=5) return vec[n-1];
        else{
            string ts = "";
            for(int i=5; i<n; ++i){
                int j, k;
                string ts;
                for(j=0; j<vec.back().size();){
                    for(k=j; vec.back()[k]==vec.back()[j]; ++k);
                    ts += (k-j) + '0';
                    ts += vec.back()[j];
                    j = k;
                }
                vec.push_back(ts);
            }
            return vec[n-1];
        }
    }
};