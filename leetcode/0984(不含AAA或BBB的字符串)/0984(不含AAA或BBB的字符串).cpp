class Solution {
public:
    string strWithout3a3b(int a, int b) {
        ostringstream oss;
        int A, B;
        char x, y;

        if(a>=b){
            A = a;
            B = b;
            x = 'a';
            y = 'b';            
        }
        else{
            A = b;
            B = a;
            x = 'b';
            y = 'a';
        }

        while(A){
            for(int i=0; i<2 && A>0; ++i){
                oss<<x;
                --A;
            }
            if(B){
                oss<<y;
                --B;
            }
            
        }
        if(B){
            ostringstream oss2;
            string t = oss.str();
            for(auto &i : t){
                oss2<<i;
                if((x==i) && B>0){
                    oss2<<y;
                    --B;
                }
            }
            return oss2.str();
        }
        else 
            return oss.str();
    }
};
