/*
从左到右遍历，每遇到一个字符，则另外开一个循环把整个参数取掉
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string inp;
    while(getline(cin, inp)){
        vector<string> ans;
        int i = 0;
        while(i<inp.size()){ 
            if(inp[i]!=' '){
                if(inp[i] == '"'){
                    int j = i+1;
                    while(j<inp.size() && inp[j]!='"') ++j;
                    ans.push_back(inp.substr(i+1, j-i-1));
                    i = j+1;
                }
                else{
                    int j = i;
                    while(j<inp.size() && inp[j]!=' ') ++j;
                    ans.push_back(inp.substr(i, j-i));
                    i = j+1;
                }
                
            }
            else{
                ++i;
            }
            
        }
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); ++i){
            cout<<ans[i]<<endl;
        }
    }
    
    return 0;
}