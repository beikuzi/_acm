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
    	c[i]=min(c[i-1],d[i-1]+1)+v[i];//ֻ����c�����λ�������ı���¼�� 
    	d[i]=min(c[i-1],d[i-1]-1)+(10-v[i]);//��Ϊ�����һλ��ǰһλ�Ͳ���һ�������� 
    }
    printf("%lld",min(c[len-1],d[len-1]+1));
    return 0;
}
