/*#include <stdio.h>

int main()
{
    int N,a,b;
    scanf("%d",&N);

        for (int i=0;i<N;i++)

        {scanf("%d%d",&a,&b);
        printf("%d\n",a+b);}


    return 0;
}
*/
#include <stdio.h>
int p[1000];
 int main()
 {
    int n,a,b,i;
   while (scanf("%d",&n)!=EOF)
 {
    for(i=0;i<n;i++)
 {
    scanf("%d%d",&a,&b);
    p[i]=a+b;
 }
    for(int i=0;i<n;i++)               //如果在这里用while，i=0要放对位置
    {
      printf("%d\n",p[i]);
    }
 }
 return 0;
 }











