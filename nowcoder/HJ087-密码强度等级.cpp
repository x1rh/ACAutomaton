/*
看着简单，却wa了好几发wa在细节上的模拟
*/


#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool ch=false, nu=false, sy=false, up=false;

int pw_len(string &str){
    if(str.size() <= 4) return 5;
    else if(5<=str.size() && str.size()<=7) return 10;
    else return 25;
}

int pw_ch(string &str){
    int upper = 0;
    int lower = 0;
    for(int i=0; i<str.size(); ++i){
        if(('a'<=str[i] && str[i]<='z')){
            ++lower;
        }
        else if(('A'<=str[i] && str[i]<='Z')){
            ++upper;
        }
    }
    if(lower==0 && upper==0) {
        ch = false; 
        return 0;
    }
    
    else if (lower>0 && upper>0) {
        up = true;
        ch = true;
        return 20;
    }
    else if(lower>0&&upper==0 || upper>0&&lower==0) {
        ch = true;
        return 10;
    }
}

int pw_num(string &str){
    int cnt=0;
    for(int i=0; i<str.size(); ++i){
        if('0'<= str[i] && str[i]<='9') ++cnt;
    }
    if(cnt==0) return 0;
    else if(cnt==1) {
        nu = true;
        return 10;
    }
    else if(cnt>1) {
        nu = true;
        return 20;
    }
}

int pw_sym(string &str){
    int cnt = 0;
    
    for(int i=0; i<str.size(); ++i){
        if((0x21<=str[i]&&str[i]<=0x2f) ||
           (0x3a<=str[i]&&str[i]<=0x40) ||
           (0x5b<=str[i]&&str[i]<=0x60) ||
           (0x7b<=str[i]&&str[i]<=0x7e)
          ) ++cnt;
    }
    if(cnt==0) return 0;
    else if(cnt==1) {
        sy = true;
        return 10;
    }
    else if(cnt>1) {
        sy = true;
        return 25;
    }
}

int main(){
    string pw;
    
    while(getline(cin, pw, '\n')){
        ch=false, nu=false, sy=false, up=false;
        int score = pw_ch(pw) + pw_len(pw) + pw_num(pw) + pw_sym(pw);

        if(up&&nu&&sy) score += 5;
        else if(ch&&nu&&sy) score += 3;
        else if(ch&&nu) score += 2;
        
        if(score>=90) cout<<"VERY_SECURE"<<endl;
        else if(score>=80) cout<<"SECURE"<<endl;
        else if(score>=70) cout<<"VERY_STRONG"<<endl;
        else if(score>=60) cout<<"STRONG"<<endl;
        else if(score>=50) cout<<"AVERAGE"<<endl;
        else if(score>=25) cout<<"WEAK"<<endl;
        else if(score>=0) cout<<"VERY_WEAK"<<endl;
        
    }
    
    return 0;
}