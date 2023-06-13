#include <stdio.h>
double x[1000];
int main()
{
    int i,n,a,b,c;
    while (scanf("%d",&n)!=EOF)
    {
        if (n!=0)
        {
          a=b=c=0;
        for (i=0;i<n;i++) scanf("%lf",&x[i]);       //注意的地方时输入有小数，所以把数组定义为浮点的，不然出错
        for (i=0;i<n;i++)
        {
            if(x[i]<0) a+=1;
            if(x[i]==0) b+=1;
            if(x[i]>0) c+=1;
        }
        printf("%d %d %d\n",a,b,c);
        }
        else return 0;

    }
    return 0;
}
