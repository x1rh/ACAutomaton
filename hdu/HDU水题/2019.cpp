#include <stdio.h>
int a[1000];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int c=0;
        if (n==0&&m==0) return 0;
       for(int i=0;i<n;i++) scanf("%d",&a[i]);
       if (m<=a[0])
        {
           printf("%d",m);
           for(int i=0;i<n;i++)
           {
               printf (" %d",a[i]);
                if (i==n-1) printf("\n");
           }
        }
       else
       {
           for(int j=0;j<n;j++)
          {
           if (m>a[j]) c++;
          }
        for (int k=0;k<c;k++)
        {
            if (k==0)
            printf("%d",a[k]);
            else printf(" %d",a[k]);
        }
        printf(" %d",m);
        for (int l=c;l<n;l++)
        {
            printf(" %d",a[l]);
            if (l==n-1) printf("\n");
        }
        }
    }
    return 0;
}
