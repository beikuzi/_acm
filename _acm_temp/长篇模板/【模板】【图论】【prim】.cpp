#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+7,maxm=1e6+7;
typedef long long ll;
int k=-1,head[maxn],vis[maxn];
int n,m;
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
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
//----------------------------------------
#define M make_pair
int dis[maxn];
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
int prim(int x){
	int cnt=0,res=0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push(M(0,x));
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;vis[u]=1,cnt++;
		res+=d;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>w){//相邻点的最小代价 
				dis[v]=w;
				q.push(M(w,v));
			}
		}
	}
	if(cnt!=n)return -1;
	return res;
}
void init(){
	memset(head,-1,sizeof(head));
	n=readi(),m=readi();
	register int u,v,w;
	for(int i=1;i<=m;i++){
		u=readi(),v=readi(),w=readi();
		add(u,v,w);
		add(v,u,w);
	}
}
void solve(){
	printf("%d",prim(1));
}
int main()
{
    init();
    solve();
    return 0;
}
