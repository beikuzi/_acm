#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
const int maxm=1e6+7;
const int inf=1e8;
int cnt[maxn],dis[maxn],head[maxn],k=-1;
int n,m;
struct edge{
	int v,w,next;
}e[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
queue<int>q;
bool spfa(int x){
	memset(cnt,0,sizeof(cnt));
	q.push(x);dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(cnt[u]>n+1)return true;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]<dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
	return false;
}

void init(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
}
int main()
{
    init();
	spfa(1);
	if(dis[n])printf("%d",dis[n]);
	else printf("-1");
	return 0;
}
