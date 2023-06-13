#include <stdio.h>
#include <string.h>
char s[100];
char v[100];
int p[100]={0};
int main()
{
    int a,b;
    int n;
    while (scanf("%d",&n)!=EOF)   //（）！=1不是等价的吗。。。。
    {
        scanf("%s%s",s,v);
        a=strlen(s);
        b=strlen(v);

        for (int i=b-1;i>=0;i--)       // 现在默认v的比较长
        {

               p[i]=v[i]+s[i-b+a]+p[i]-96;   //字符相加，醉了，还是改成ASCII相加减96.。。。再加上它本身
               if(p[i]>=10)
               {
                   p[i-1]++;   //p[-1]会是什么情况
                   p[i]=p[i]-10;
               }               //套的两层循环，里层break出来会再循环进去吗
        }
        for (int k=0;k<b;k++)       //妈呀，连输出都是问题，循环输出的个数会被满十进一干扰
        printf("%d",p[k]);
    }
    return 0;
}
