#include <stdio.h>
int main()
{
    int n,m,k,p;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        k=n/m;
        if (n%m==0)
        {
        for (int i=0;i<k;i++)
        {
           p=(i*m+(i+1))*2+m-1;
           printf("%d\n",p);
        }
        }
        else
        {
           for (int j=0;j<k+1;j++)
           {
               p=(j*m+(j+1))*2+m-1;
               while (j<k) printf("%d",p);
               if (j=k) printf("%d\n",p-1);
           }
        }
    }
        return 0;
}
