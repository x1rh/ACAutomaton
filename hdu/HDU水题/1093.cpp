#include <stdio.h>
int p[1000];
int main()
 {
    int n,sum,m;
    scanf("%d",&n);

        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&m);
            for (int k=0;k<m;k++)
            {
                scanf("%d",&p[k]);
                sum=sum+p[k];
            }
            printf("%d\n",sum);
            sum=0;
        }

        return 0;
 }
