#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
char ch[maxn];
int v[maxn];
ll c[maxn],d[maxn];
int main()
{
    scanf("%s",ch);
    int len=strlen(ch);
    for(int i=0;i<len;i++){
    	v[i]=ch[i]-48;
    }
    c[0]=v[0];
    d[0]=10-v[0];
    for(int i=1;i<len;i++){
    	c[i]=min(c[i-1],d[i-1]+1)+v[i];//只有在c这里，借位才真正的被记录了 
    	d[i]=min(c[i-1],d[i-1]-1)+(10-v[i]);//因为多借了一位，前一位就不用一个花费了 
    }
    printf("%lld",min(c[len-1],d[len-1]+1));
    return 0;
}
