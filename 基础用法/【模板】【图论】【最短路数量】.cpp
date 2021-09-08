#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue> 
using namespace std;
int n,m;
const int maxn=1e5,maxm=1e4;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn],vis[maxn],dis[maxn],cnt,num[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	e[k].v=v,e[k].w=w;
	head[u]=k;
}
typedef pair<int,int>pii;
#define M make_pair
priority_queue<pii,vector<pii>,greater<pii> >q;
void dijk(int x){
	dis[x]=0;
	num[x]=1;
	q.push(M(0,x));
	while(!q.empty() and cnt<n){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;vis[u]=1;
		cnt++;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(d+w==dis[v])num[v]+=num[u];
			if(d+w<dis[v]){
				dis[v]=d+w;
				num[v]=num[u];
				q.push(M(dis[v],v));
			}
		}
	}
}
int main()
{
    int t;scanf("%d",&t);
    int u,v,w;
    for(int i=1;i<=t;i++){
    	scanf("%d%d",&n,&m);
    	memset(head,0,sizeof(head));
    	memset(dis,0x3f,sizeof(dis));
    	memset(vis,0,sizeof(dis));
    	memset(num,0,sizeof(num));
    	cnt=0;k=0;
    	for(int i=1;i<=m;i++){
    		scanf("%d%d%d",&u,&v,&w);
    		add(u,v,w);
    	}
		int srt,end;scanf("%d%d",&srt,&end);
		dijk(srt);
		printf("%d\n",num[end]);
    }
    return 0;
}
