#include <stdio.h>
#include <math.h>
int main()
{
    int x,y,n,i,temp,j;
    while (scanf("%d %d",&x,&y)!=EOF)
    {

        if (x==0&&y==0) return 0;
        else
        {
            n=0;
            for (i=x;i<y+1;i++)
        {
            j=i*i+i+41;
            for (int a=2;a<j;a++)
            {
               if(j%a==0) n++;   //这里我一开始用j%a!=0，这个逻辑是错的，非质数第一次除可能余数不为零，但是n加了1；后面判断的时候用n！=0来判断输出质数就错了
            }

        }
        if (n==0) printf("OK\n");
        else printf("Sorry\n");
    }
    }
    return 0;
}

