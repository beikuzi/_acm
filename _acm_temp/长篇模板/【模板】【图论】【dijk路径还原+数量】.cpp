#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
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
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
struct edge{
	int v,w,next;
}e[maxm];
int k=-1,head[maxn],vis[maxn],dis[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int num[maxn],pre[maxn];
int n,m;
#define M make_pair
typedef long long ll;
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
void dijk(int x){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(num,0,sizeof(num));
	memset(pre,0,sizeof(pre));
	dis[x]=0,num[x]=1;
	q.push(M(0,x));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]==dis[u]+w)num[v]+=num[u];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				num[v]=num[u];
				pre[v]=u;
				q.push(M(dis[v],v));
			}
		}
	}
}
void init(){
	memset(head,-1,sizeof(head));
	n=readi(),m=readi();
	register int u,v,w;
	for(int i=1;i<=m;i++){
		u=readi(),v=readi(),w=readi();
		add(u,v,w);
		//add(v,u,w);
	}
}
void get_path(int x){
	while(x){
		printf("%d ",x);
		x=pre[x];
	}
}
void solve(){
	dijk(1);
	for(int i=1;i<=n;i++){
		printf("%d ",dis[i]);
	}printf("\n");
	printf("%d\n",num[n]);
	get_path(n);
}
int main()
{
    init();
    solve();
    return 0;
}
