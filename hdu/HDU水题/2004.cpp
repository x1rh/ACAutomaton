#include <stdio.h>
int a[1000];
int main()
{
    int n,i,j=0;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    if (0<=a[i]&&a[i]<=100)
    {
        for (i=0;i<n;i++)
        {
            if (90<=a[i]&&a[i]<=100) printf("A\n");
            if (80<=a[i]&&a[i]<=89) printf("B\n");
            if (70<=a[i]&&a[i]<=79) printf("C\n");
            if (60<=a[i]&&a[i]<=69) printf("D\n");
            if (0<=a[i]&&a[i]<=59) printf("E\n");
            j=1;
        }
    }
    if (0>=a[i]||a[i]>=100)  printf("Score is error!\n"); //为什么这里用else和用if (0>=a[i]||a[i]>=100)的效果不一样！！！
    return 0;
}
