#include <stdio.h>
#include <math.h>
int x[100];
int main()
{
    int m,i,j;
    double a,sum;
    while (scanf("%d",&m)!=EOF)
    {
       for (i=0;i<m;i++) {scanf("%d",&x[i]);
            a=0;
            sum=0;
           for (j=1;j<=x[i];j++)
         {
             a=1.0/j;
            if(j%2!=0) sum+=a;

            else sum-=a;

        }
        printf("%.2lf\n",sum);
        }
    }
    return 0;

}
