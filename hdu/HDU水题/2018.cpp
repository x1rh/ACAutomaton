#include <stdio.h>
int a[100];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        a[0]=1;
        a[1]=2;
        a[2]=3;
        a[3]=4;
        for(int i=4;i<n;i++)
        {
            a[i]=a[i-1]+a[i-3];
        }
        printf("%d\n",a[n-1]);
    }
    return 0;
}
