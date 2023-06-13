#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    double m,x1,y1,x2,y2;
    while (scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
    {

        m=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2lf\n",m);
    }
    return 0;
}
