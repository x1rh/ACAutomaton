/*
#include<stdio.h>
int mod(int key)
{
    while(key>=10){
        if(key-(key/10)*10==0)
        return 0;
        else return(mod(key%10));
    }
    return key;
}
int main()
{
    long long n,key,t;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld",&key);
        if(mod(key)==0){
        printf("0\n");
        continue;
        }
        t=key;
        for(int i=1;i<t;i++){
            key=t*mod(key);
        }
    printf("%d\n",mod(key));
    }
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
#define mod 1000000007
long long quick_pow(int n,int base)
//n是指数 base是底 即计算的是base^n 当然结果是取模了的
{
    long long ans=1;//默认ans大于等于1因为不能算负指数
    long long multi=base;
    while(n)
    {
        if(n%2) ans*=multi;
        ans%=mod;//由于数太大一般要取模
        n/=2;
        multi*=multi;
        multi%=mod;
    }
  return ans;
}

int main()
{
    int n,base;
    while(cin>>n>>base)
        cout<<quick_pow(n,base)<<endl;
    return 0;
}
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
//int arr[10][4] = {{0},{1},{4,8,6,2},{9,7,1,3},{6,4},{5},{6},{9,3,1,7},{4,2,8,6},{1,9}};
int arr[10][4] = {{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
int main()
{
    int n,t;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        int a = t%10;
        if(a==0||a==1||a==5||a==6)
            printf("%d\n\n",a);
        else if(a==4||a==9)
            printf("%d\n\n",arr[a][t%2]);
        else printf("%d\n\n",arr[a][t%4]);
    }
    return 0;
}

/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF){
            long long sum = 1;
    for(int i=0;i<n;i++)
    {
        sum *= n;
    }
    printf("%lld\n",sum);
    }
}
*/
/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[10][4] = {{0},{1},{6,2,4,8},{1,3,9,7},{6},{5},{6},{1,7,9,3},{6,8,4,2},{9}};
int main()
{
    int n,t;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        int a = t%10;
        if(a==0||a==1||a==5||a==6)
            printf("%d\n",a);
        else if(a==4||a==9)
            printf("%d\n",arr[a][0]);
        else printf("%d\n",arr[a][t%4]);
    }
    return 0;
}
*/






















