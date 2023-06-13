#include <cstdio>

using namespace std;
const int maxn = 10005;
int A[maxn];

int main(){
	int n, first, last, st;
	while(~scanf("%d", &n)){
		for(int i=0; i<n; i++)
			scanf("%d", &A[i]);

		bool flag = false;
		int ThisSum=0, MaxSum=0, st = A[0];;
		for(int i=0; i<n; i++){
			ThisSum += A[i];
			if(ThisSum >= MaxSum){
				if(ThisSum!=MaxSum ||(ThisSum==0&&MaxSum==0)){
					MaxSum = ThisSum;
					first = st;
					last = A[i];
					flag = true;
				}
			}
			else if(ThisSum < 0){
				ThisSum = 0;
				st = A[i+1];
			}
		}
		if(!flag)
			printf("0 %d %d\n", A[0], A[n-1]);
		else
			printf("%d %d %d\n", MaxSum, first, last);
	}
	return 0;
}
