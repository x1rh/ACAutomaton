#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 10005;
const int INF = 0x3f3f3f3f;
int pre[maxn];
bool flag;
vector<int> con;

void init(){
	for(int i=0; i<maxn; i++)
		pre[i] = i;
}

int Find(int key){
	if(pre[key] == key)
		return key;
	return pre[key] = Find(pre[key]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x!=y) pre[x] = y;
}

bool CheckExist(vector<int> &v, int key){
	int Size = v.size();
	for(int i=0; i<Size; i++)
		if(v[i] == key) return true;
	return false;
}

int CheckConnect(int n){
    if(!flag) return n; //judge whether had operated
	vector<int> ans;
	int Size = con.size();
	for(int i=0; i<Size; i++){
		int x = Find(con[i]);
		if(!CheckExist(ans, x))
			ans.push_back(x);
	}
	return ans.size();
}

int main(){
	int n, x, y;
	char opt;
	while(cin>>n){
		con.clear(); init(); flag = false;
        while(true){
        	cin>>opt;
			if(opt!='S'){
				cin>>x>>y;
				con.push_back(x); con.push_back(y);
				if(opt=='I'){
                    Union(x, y);
                    flag = true;
				}
				else{
					x = Find(x);
					y = Find(y);
					if(x != y)
						cout<<"no"<<endl;
					else
						cout<<"yes"<<endl;
				}
			}
			else{
				int check = CheckConnect(n);
				if(check == 1)
					cout<<"The network is connected."<<endl;
				else
					cout<<"There are "<<check<<" components."<<endl;
                //for(int i=1; i<=n; i++) cout<<pre[i]<<" ";cout<<endl;
				break;
			}
        }
	}
	return 0;
}
