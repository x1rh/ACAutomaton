#include <stdio.h>
int main()
{
    int n,i,a;
    while (scanf("%d",&n)!=EOF)
    {
        a=1;
        for (i=0;i<n-1;i++)
        {
            a=(a+1)*2;
        }
        printf("%d\n",a);
    }
    return 0;
}
