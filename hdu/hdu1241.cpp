#include <iostream>
#include <string.h>
#include <cstdio>

int m, n;
const int maxn = 1000+10;
char arr[maxn][maxn];
int dir[8][2] = {{-1,0},{-1,-1},{-1,1},{0,1},{0,-1},{1,1},{1,0},{1,-1}};

using namespace std;

void DFS(int x, int y)
{
	for(int i=0;i<8;i++)
	{
		int ddx = dir[i][0] + x;
		int ddy = dir[i][1] + y;
		if(0<=ddx && ddx<m && 0<=ddy && ddy<n && arr[ddx][ddy]=='@')
		{
			arr[ddx][ddy] = '*';
			DFS(ddx, ddy);
		}
	}
}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
   while(scanf("%d%d",&m,&n))
   {
      int ans=0;
      if(m==0 && n==0) break;
      memset(arr,0,sizeof(arr));
      for(int i=0; i<m;i++)
		  for(int j=0; j<n; j++)
			  cin>>arr[i][j];

      for(int i=0; i<m; i++)
         for(int j=0; j<n; j++){
            if(arr[i][j] == '@'){
               arr[i][j] = '*';
               ans++;
               DFS(i, j);
            }
         }
		cout<<ans<<endl;
   }
   return 0;
}
