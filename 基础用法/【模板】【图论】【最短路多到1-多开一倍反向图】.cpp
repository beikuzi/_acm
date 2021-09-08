#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=(1e6+7)*2,maxm=(1e6+7)*2;//单向，但是来回 
typedef long long ll;
struct edge{
	int v,w,next;
}e[maxm];
int n,m;
int k,dis[maxn],head[maxn],vis[maxn],cnt;
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
#define M(x,y) make_pair(x,y)
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
ll dijk(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(M(0,x));dis[x]=0;cnt=0;
	ll res=0;
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;vis[u]=1;cnt++;
		res+=d;//注意，如果这么写，这个点要取出来加，所以cnt的优化就没有用了…… 
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(M(dis[v],v));
			}
		}
	}
	return res;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v+n,u+n,w);//相当于 建两份图 
	}
	ll ans=0;
	ans+=dijk(1);
	ans+=dijk(1+n);
	printf("%lld",ans);
    return 0;
}
