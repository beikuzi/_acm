#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn=1e5+7,maxm=3*1e5+7;//²»ÐèÒª2±¶
struct edge{
	int u,v,w;
}e[maxm];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int f[maxn];
int cfind(int x){
	if(f[x]==x)return x;
	return f[x]=cfind(f[x]);
}
int n,m;
typedef long long ll;
ll ans;
int cnt;
void krus(){
	for(int i=1;i<=m;i++){
		int u=cfind(e[i].u),v=cfind(e[i].v);
		if(u==v)continue;f[u]=v;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1)return;
	}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w); 
    }sort(e+1,e+1+m,cmp);
    krus();
    printf("%lld",ans);
    return 0;
}
