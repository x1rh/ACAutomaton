class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
    
        ostringstream oss;        

        long long n = numerator;
        long long d = denominator;
        
        if(n*d < 0) oss<<"-";
        n = abs(n);
        d = abs(d);
        
        long long a = floor(n/d);
        long long l = n%d;
        oss<<a;

        if(l==0){
            return oss.str();
        }
        else{
            oss<<".";
            map<int, int> mp;
            vector<int> v;
            bool flag = false;
            while(l!=0){
                int cur = floor(l*10/d);
                v.push_back(cur);
                mp[l] = v.size()-1;
                
                l = (l*10) % d;
                
                if(mp.find(l) != mp.end()){
                    for(int i=0; i<mp[l]; ++i){
                        oss<<v[i];
                    }
                    oss<<"(";
                    for(int i=mp[l]; i<v.size(); ++i){
                        oss<<v[i];
                    }
                    oss<<")";
                    return oss.str();
                }   
            }
            for(auto &x : v){
                oss<<x;
            }
            return oss.str();
        }
    }
};