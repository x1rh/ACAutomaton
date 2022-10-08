class Solution {
public:
    struct Node{
        int p, c;
        Node(int p, int c):p(p), c(c){}

        bool operator<(const Node& rhs)const{
            if(this->p < rhs.p) return true;
            else if(this->p == rhs.p) return this->p < rhs.p;
            else return false;
        }
    };
    
    class cmp{
        public:
            bool operator()(const Node& lhs, const Node& rhs){
                if(lhs.c > rhs.c) return true;
                else if(lhs.c == rhs.c) return lhs.p < rhs.p;
                else return false;
            }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        priority_queue<Node> pq;
        priority_queue<Node, vector<Node>, cmp> bc;
        for(int i=0; i<n; ++i){
            pq.emplace(profits[i], capital[i]);
        }

        for(int i=0; i<k; ++i){
            while(!pq.empty()){
                Node tp = pq.top(); 
                pq.pop();
                if(tp.c <= w){
                    w += tp.p;
                    break;
                }
                else{                
                    bc.push(tp);
                }
            }
            while(!bc.empty()){
                Node tp = bc.top();
                if(tp.c <= w){
                    bc.pop();
                    pq.push(tp);
                }
                else{
                    break;
                }
            }        
        }
        return w;
    }
};