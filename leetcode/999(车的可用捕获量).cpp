#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

template <typename T>
void print(vector<T>& v){
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template<typename T>
void print(vector<vector<T>>& v){
    for(auto iti=v.begin(); iti!=v.end(); ++iti){
        for(auto itj=(*iti).begin(); itj!=(*iti).end(); ++itj){
            cout<<*itj<<" ";
        }
        cout<<endl;
    }
}

class Solution {
public:

    int numRookCaptures(vector<vector<char>>& board) {
        int ii=-1, jj=-1, dx, dy, ans=0;
        for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                if(board[i][j]=='R'){
                    ii = i;
                    jj = j;
                    break;
                }
            }
            if(ii!=-1) break;
        }

        dx = ii;
        dy = jj;
        while(--dx>=0){
            if(board[dx][dy]=='B') break;
            else if(board[dx][dy] == '.') continue;
            else if(board[dx][dy] == 'p'){
                ++ans;
                break;
            }
        }

        dx = ii;
        dy = jj;
        while(++dx<8){
            if(board[dx][dy]=='B') break;
            else if(board[dx][dy] == '.') continue;
            else if(board[dx][dy] == 'p'){
                ++ans;
                break;
            }
        }

        dx = ii;
        dy = jj;
        while(--dy>=0){
            if(board[dx][dy]=='B') break;
            else if(board[dx][dy] == '.') continue;
            else if(board[dx][dy] == 'p'){
                ++ans;
                break;
            }
        }

        dx = ii;
        dy = jj;
        while(++dy<8){
            if(board[dx][dy]=='B') break;
            else if(board[dx][dy] == '.') continue;
            else if(board[dx][dy] == 'p'){
                ++ans;
                break;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v({6});

    return 0;
}