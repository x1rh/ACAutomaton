class Solution {
public:
    struct Node {
        int cnt;
        char x;
        Node(int cnt, char x):cnt(cnt), x(x){}
        bool operator<(const Node& rhs)const{
            return this->cnt > rhs.cnt;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        vector<Node> arr = {Node(a, 'a'), Node(b, 'b'), Node(c, 'c')};
        ostringstream oss;
        while(1){
            sort(arr.begin(), arr.end());
            bool flag = false;
            for(auto &x : arr){
                if(x.cnt <= 0) break;

                int sz = oss.str().size();

                if(sz>=2 && oss.str()[sz-1]==x.x && oss.str()[sz-2]==x.x){
                    continue;
                }
                oss<<x.x;
                --x.cnt;
                flag = true;
                break;
            }
            if(!flag) break;

        }
        return oss.str();
    }
};