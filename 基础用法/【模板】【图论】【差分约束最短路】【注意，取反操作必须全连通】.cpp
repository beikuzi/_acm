#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int maxn=1e5+7,maxm=maxn<<1;
int inf=0x3f3f3f3f;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn],cnt[maxn],dis[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int n,m;
typedef long long ll;
queue<int>q;
bool spfa(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	q.push(x);dis[x]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(cnt[u]>n+1)return true;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;
				q.push(v);
			}
			
		}
	}
	return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	add(v,u,w);
    }
    for(int i=1;i<=n;i++){
    	add(0,i,0);
    }
    int d=inf; 
    if(spfa(0)){
    	printf("NO");
    	return 0;
    }
    else for(int i=1;i<=n;i++){
    	d=min(d,dis[i]);
    }
    for(int i=1;i<=n;i++)printf("%d ",dis[i]+d);
	return 0;
}
