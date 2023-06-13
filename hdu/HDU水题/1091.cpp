#include <stdio.h>
int main()
 {
    int n,a,b,i;
    while (scanf("%d%d",&a,&b)!=EOF)         //有毒啊，这题我还以为要输入两组数据。。。。。
    {
        if (a==0&&b==0) return 0;
        printf("%d\n",a+b);
    }
        return 0;
 }
