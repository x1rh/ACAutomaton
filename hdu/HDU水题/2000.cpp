#include <stdio.h>

int main()
{
    char a,b,c,tmp;
    while(scanf("%c%c%c%c",&a,&b,&c)!=EOF)
    {



        if(a>b)
        {
            tmp=a;    //a，代表最小，b代表第二小，c代表最大
            a=b;
            b=tmp;
        }
        if(a>c)
        {
            tmp=a;
            a=c;
            c=tmp;
        }
        if(b>c)
        {
            tmp=b;
            b=c;
            c=tmp;
        }
        printf("%c %c %c\n",a,b,c);   //写了if可以没有else

    }
    return 0;
}
