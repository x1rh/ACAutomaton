class Solution {
public:
    char con(int x){
        if(x<10){
            return '0' + x;
        }
        else{
            return 'a' + x - 10;
        }
    }

    string toHex(int num) {
        if(num==0) return "0";
        
        string ans;
        uint32_t k = num;

        while(k){
            ans = con(k % 16) + ans;
            k /= 16;
        }
        return ans;
    }
};