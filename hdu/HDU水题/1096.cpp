
#include <stdio.h>
int main()
{
    int a,n,m,sum;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        sum=0;
        while (m--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
        if (i!=n-1)
        printf("\n",sum);        //可以先跳一行再判断，意思是最后的结果还跳了一行。。。。。。好吧，好像最后的结果就是要跳一行
    }
    return 0;
}
