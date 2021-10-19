#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e5+7,maxm=1e6+7;
typedef long long ll;
struct edge{
	int u,v,w;
}e[maxm];
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
inline ll readl(){
	ll x=0,b=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int f[maxn];
int cfind(int x){
	return (f[x]==x)?x:f[x]=cfind(f[x]);
}
int n,m;
int krus(){
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=cfind(e[i].u),v=cfind(e[i].v);
		if(u==v)continue;f[u]=v;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1)return ans;
	}return ans;
}

void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		e[i].u-readi();
		e[i].v=readi();
		e[i].w=readi();
	}
}
void solve(){
	sort(e+1,e+1+m,cmp);
	printf("%d",krus());
}
int main()
{
    init();
    solve();
    return 0;
}
