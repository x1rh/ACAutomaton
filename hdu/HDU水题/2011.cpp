#include <stdio.h>
int x[100];
int main()
{
    int m,i,j;
    double sum,k;
    while (scanf("%d",&m)!=EOF)
    {
       for (i=0;i<m;i++)
        {
            scanf("%d",&x[i]);           //这里循环输入拆开来竟然会导致答案不一样!!!!
            k=1.0;
            sum=0;

        for (j=1;j<=x[i];j++)            //问题在于循环内部的不能再用i，要更改变量;而且要是1.0，而不是1
        {
            sum=sum+k*1.0/j;
            k=-k;
        }
        printf("%.2lf\n",sum);
        }
    }
    return 0;

}
