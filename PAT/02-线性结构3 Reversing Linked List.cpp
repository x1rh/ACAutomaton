#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

class Graph
{
public:
	int n;
	int **tu;
	int **arr;
	map<int, int> mp;
	Graph(int n){
		this->n = n;
		arr = new int*[n];
		tu = new int*[n];
		for(int i=0; i<n; i++){
			tu[i] = new int[4];
			arr[i] = new int[4];
		}
	}
	~Graph(){
		for(int i=0; i<n; i++){
			delete []tu[i];
			delete []arr[i];
		}
		delete []tu;
		delete []arr;
	}
	void Insert(int x, int data, int y, int address, int next){
		tu[x][0] = data;
		tu[x][1] = y;
		tu[x][2] = address;
		tu[x][3] = next;
	}
	void GetArray(int start){
		int x = start, cnt=0;
		while(tu[x][1] != -1){
			arr[cnt][0] = tu[x][0];
			arr[cnt][1] = tu[x][2];
			arr[cnt++][2] = tu[x][3];
			x = tu[x][1];
		}
		arr[cnt][0] = tu[x][0];
		arr[cnt][1] = tu[x][2];
		arr[cnt++][2] = tu[x][3];
	}
	void display(){
		for(int i=0; i<n-1; i++){
			printf("%d ", arr[i][0]);
		}
		printf("\n");
	}

	void GetZero(int x){
	    if(x==0){
            printf("00000"); return;
	    }
	    if(x==-1){
            printf("-1"); return;
	    }
		int cnt=0, num=x;
		while(x){
			x/=10, cnt++;
		}
		for(int i=0; i<((5-cnt)); i++)
			printf("0");
		printf("%d", num);
	}

	void print(int cnt, int k){
        for(int i=1; i<=cnt; i++){
            for(int j=i*k-1; j>=(i-1)*k; j--){
                if(i==1 && j==i*k-1){
                    GetZero(arr[j][1]);
                }
                else{
                    GetZero(arr[j][1]);
                    printf("\n");
                    GetZero(arr[j][1]);
                }
            	printf(" %d ", arr[j][0]);
            }
        }

		for(int i=cnt*k; i<n-1; i++){
			GetZero(arr[i][1]);
			printf("\n");
			GetZero(arr[i][1]);
			printf(" %d ", arr[i][0]);
		}
		printf("-1\n");
	}

	void KIsOne(){
		for(int i=0; i<n-1; i++){
			GetZero(arr[i][1]);
			printf(" %d ", arr[i][0]);
			GetZero(arr[i][2]);
			printf("\n");
		}
	}

	void output(int k){
		int cnt = (n-1)/k;
		if(k==1)
			KIsOne();
        else
            print(cnt, k);
		return;
	}
};


int main(){
	int start, n, k, address, data, next;
	while(~scanf("%d%d%d", &start, &n, &k)){
		Graph g(n+1);
		int cnt = 1, realx, realy;
		for(int i=0; i<n; i++){
			scanf("%d%d%d", &address, &data, &next);
			if((realx=g.mp[address])==0){
				realx = g.mp[address] = cnt++;
			}
			if(next==-1){
                g.Insert(realx, data, -1, address, next);
                continue;
			}
			if((realy=g.mp[next])==0){
				realy = g.mp[next] = cnt++;
			}
			g.Insert(realx, data, realy, address, next);
		}
		g.GetArray(g.mp[start]);
		g.output(k);
	}
	return 0;
}
