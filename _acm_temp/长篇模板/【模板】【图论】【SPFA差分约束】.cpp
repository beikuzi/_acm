#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+7,maxm=1e6+7;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
inline ll readl(){
	ll x=0,b=1;
	char ch=getchar();
	while('0'>ch  or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
const int inf=1e8;
int dis[maxn],cnt[maxn],k=-1,head[maxn];
queue<int>q;
int n,m;
struct edge{
	int v,w,next;
}e[maxm];//由于超级源点也需要边，请开3倍 
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
void init(){
	n=readi(),m=readi();
	memset(head,-1,sizeof(head));
	register int u,v,w;
	for(int i=1;i<=m;i++){
		u=readi(),v=readi(),w=readi();
		add(u,v,-w);
	}
	for(int i=n;i>=1;i--){
		add(0,i,0);
	}
}
bool spfa(int x){
	memset(cnt,0,sizeof(cnt));
	memset(dis,-0x3f,sizeof(dis));
	q.push(x);dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(cnt[u]>n+1)return true;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]<dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;
				q.push(v);
			}
		}
	}
	return false;
}
void solve(){
	if(spfa(0)){
		printf("NO");
		return;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",dis[i]);
	}
}
int main()
{
    init();
    solve();
    return 0;
}
