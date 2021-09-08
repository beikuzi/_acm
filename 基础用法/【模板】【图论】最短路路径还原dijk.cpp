#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=1e4+7,maxm=1e6+7;
typedef long long ll;
const ll inf=2147483647;
struct edge{
	int v,w,next;
}e[maxm];
int head[maxn],dis[maxn],vis[maxn],k=-1;
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int pre[maxn];
int n,m,s;

#define M(x,y) make_pair(x,y)

typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
void dijk(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(dis));
	dis[x]=0;
	q.push(M(0,x));
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			//cout<<u<<' '<<v<<' '<<w<<' '<<dis[u]<<' '<<dis[v]<<endl;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pre[v]=u;
				q.push(M(dis[v],v));
			}
		}
	}
}
void init(){
	memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&s);
    int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	add(u,v,w);
    	//add(v,u,w);
    }
}
void get_path(int x){
	while(x){
		printf("%d ",x);
		x=pre[x];
	}
	printf("\n");
}
int main()
{
	init();
    dijk(s);
    for(int i=1;i<=n;i++){
    	if(dis[i]>=0x3f3f3f3f){
			printf("%lld ",inf);
			//printf("\n");
		}
    	
    	else{
    		printf("%d ",dis[i]);
    		//get_path(i);
    	}
    }
    return 0;
}
