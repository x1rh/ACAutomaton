#include <stdio.h>
#include <math.h>
int main()
{
    int n,m,i;
    double temp,sum;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        temp=n;
        sum=n;
        for (i=0;i<m-1;i++)
        {
            temp=sqrt(temp);
            sum=sum+temp;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
