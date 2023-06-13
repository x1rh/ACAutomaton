#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
char arr[20];
}str[1010];

bool cmp(node a, node b)
{
    if(strcmp(a.arr,b.arr)<0)
        return true;
    else return false;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(str,0,sizeof(str));
        for(int i=0;i<n;i++) scanf("%s",str[i].arr);
        sort(str,str+n,cmp);
        int flag=0,temp=0;
        for(int i=0;i<n;i++){
            int sum=1;
            for(int j=i+1;j<n;j++){
                    if(strcmp(str[i].arr,str[j].arr)==0)
                    sum++;
            else break;
            }
            if(temp < sum){
                temp=sum;
                flag = i;
            }
        }
        printf("%s\n",str[flag].arr);
    }
    return 0;
}
