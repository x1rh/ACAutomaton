#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 1005;
int arr[maxn];

int main(){
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while(k--){
		stack<int> s;
		for(int i=1; i<=n; i++){
			scanf("%d", &arr[i]);
		}
		int cnt = 1, i=1;
		bool flag = true;
		while(i<=n){
			if(s.size()==m && s.top()!=arr[cnt]){
				flag = false;
				break;
			}
			if(i==arr[cnt]){
				cnt++, i++;
				continue;
			}
			else{
				if(!s.empty() && s.top()==arr[cnt]){
					while(!s.empty() && s.top()==arr[cnt]){
						s.pop();
						cnt++;
					}
				}
				else{
					s.push(i), i++;
				}
			}
		}
		while(!s.empty()){
			if(s.top()!=arr[cnt]){
				flag = false;
				break;
			}
			else{
				s.pop();
				cnt++;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
