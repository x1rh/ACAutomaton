#include <stdio.h>
int a[1000];
int main()
{
    int N,M,i,sum=0;
    while (scanf("%d",&N)!=EOF)
    {
        if(N==0)
            return 0;
        for (i=0;i<N;i++) scanf("%d",&a[i]);
        scanf("%d",&M);
        for (i=0;i<N;i++)
        {
            if (a[i]==M)
            sum++;
        }
        printf("%d\n",sum);
        sum=0;             //这里没有返回0竟然会影响下一次输出。。。。。前面不是sum=0了吗。。。。


    }
    return 0;
}
