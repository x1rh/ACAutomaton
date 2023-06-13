#include <stdio.h>
int main()
{
int n,c,sum;
scanf("%d ",&n);
while (n--)
{
    sum=0;
    while ((c = getchar()) != '\n')
    {
        if('0'<=c&&c<='9')
        sum++;
    }
    printf("%d\n", sum);

}
return 0;
}


#include <stdio.h>
char a[100];
int p[100];
int  main()
{
    int n,sum,b;
    scanf("%d",&n);
    while (n--)
    {
        sum=0;

       scanf("%s",a);
       b=sizeof a / sizeof a[0];
       for (int i=0;i<b;i++)
       {
           if('0'<=a[i]&&a[i]<='9')
            sum++;
       }
    printf("%d\n",sum);
    }
   return 0;
}
