#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long long   n,i=0;
    long long  sum=0;
    while(scanf("%lld",&n)!=EOF)
    {
      for (i=0;i<n+1;i++)
      {
          sum=sum+i;
      }

      printf("%lld\n\n",sum);
      sum=0;
    }


    return 0;


}
