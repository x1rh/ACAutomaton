#include <stdio.h>
int p[1000];
int main()
 {
    int n,sum;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            sum=sum+p[i];
        }
        printf("%d\n",sum);
    }
        return 0;
 }
