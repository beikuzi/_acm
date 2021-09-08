#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int n,m,s;
const int maxn=1e5,maxm=1e6+7;
const int inf=0x7fffffff;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn];
void add(int u,int v,int w){
	k++;
	e[k].v=v,e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
int dis[maxn],cnt[maxn];
queue<int>q;
bool spfa(int x){
	dis[x]=0;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(cnt[u]>=n)return 1;//这个结点被循环过好几次 
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			//cout<<u<<' '<<v<<' '<<w<<endl;
			//cout<<dis[u]<<' '<<dis[v]<<endl;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;//数被增加的次数 
				q.push(v);
			}
		} 
	}
	return 0;
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
	memset(head,0,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		//add(v,u,w);
	}
	spfa(s);
	for(int i=1;i<=n;i++){
		if(dis[i]==0x3f3f3f3f)printf("%d ",inf);
		else printf("%d ",dis[i]);
	}
	return 0;
}
