#include <stdio.h>
int main()
{
    int m,n,i;
    int a,b,c,j=0,k=0;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        for (i=m;i<n+1;i++)
        {
            a=i/100;
            b=(i-a*100)/10;
            c=(i-a*100-b*10);
            if(i==(a*a*a+b*b*b+c*c*c))
            {
                if(j==0)
                    {
                        printf("%d",i);
                        j++;
                    }
                else printf(" %d",i);
                k=1;
            }
        }
            if (k==1) printf("\n");
            else printf("no\n");

        k=j=0;
    }
    return 0;
}
