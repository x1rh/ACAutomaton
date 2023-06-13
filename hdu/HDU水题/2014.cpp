#include <stdio.h>
int a[1000];
int main()
{
    int n;
    double p,b,c,sum;
    while (scanf("%d",&n)!=EOF)
    {
        c=100.0;
        b=0;
        sum=0;              //sum竟然忘记返回值了
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            if (a[i]<=c) c=a[i];   //把整数赋值进浮点值没变。。。？
            if (a[i]>=b) b=a[i];
            sum=sum+a[i];
        }
        p=(sum*1.0-c-b)/(n-2);  //注意浮点数
        printf("%.2lf\n",p);

    }
    return 0;
}
