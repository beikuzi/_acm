#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
#include<queue>
using namespace std;
const int maxn=1e3+7,maxm=1e4+7;
typedef long long ll;
struct edge{
	ll v,w,next;
}e[maxm];
int head[maxn],vis[maxn],pre[maxn],k=-1;//注意k 
ll dis[maxn];//利用了奇数xor1相当于-1，偶数xor1是 +1
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
bool bfs(int s,int t){
	queue<ll>q;//注意写在bfs里面，因为结束时未清空 
	memset(vis,0,sizeof(vis));
	dis[s]=2e9;//1.源头塞满水 
	q.push(s);vis[s]=1;//2.压入结点 
	
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=e[i].next){
			//这里有两种方式，一种是推进去后立刻vis，一种是取出来是用vis
			//由于dijk原理是贪心最短点，点被压入很多次，所以只能取出来vis
			//Ek算法无论怎么走，点只接触一遍,推进去vis 
			ll v=e[i].v,w=e[i].w;
			if(!w or vis[v])continue;//3.判断是否满足条件 
			dis[v]=min(dis[u],w);//4.这个是覆盖式更新，所以dis不用memset 
			q.push(v);vis[v]=1;//5.压入结点 
			pre[v]=i;//6.为dfs做准备，并判断是否满足 退出并dfs 
			if(v==t)return 1;
		}
	}return 0; 
}
ll dfs(int s,int t){
	int u=t;
	while(u!=s){
		int i=pre[u];//1.找前驱边 
		e[i].w-=dis[t];//2.正向减少，反向增加 
		e[i^1].w+=dis[t];
		u=e[i^1].v;//3.循环上一个结点 
	}return dis[t]; 
}
int n,m,s,t;
int loc[maxn][maxn];
int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&s,&t);
    int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	if(loc[u][v]==0){//1.判断是不是重边 
    		add(v,u,0);//2.正向和反向 
    		add(u,v,w);
    		loc[u][v]=k;//3.记录位置 
    	}
    	else e[loc[u][v]].w+=w;//4.重边 
    }
    ll ans=0;
    while(bfs(s,t)){
    	ans+=dfs(s,t);
    }printf("%lld",ans);
    return 0;
}
