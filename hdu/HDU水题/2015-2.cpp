#include <stdio.h>
int p[1000];
int main()
{
    int n,m,k,j=0,u;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        k=n/m;
       for (int i=0;i<k+1;i++)
        {
           p[i]=i*m*2+m+1;
        }
        if (k==0) u=0;
        else u=1;
        while (u==0,j<k)
            {
                printf("%d",p[j]);
                j++;
            }
        while (u==1,j<k)
           {
              printf("%d",p[j]);
              j++;
              while (j==k+1)
              printf("%d",p[k]-1);
           }
        }
     return 0;
}
