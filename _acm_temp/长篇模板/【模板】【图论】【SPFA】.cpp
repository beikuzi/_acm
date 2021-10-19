#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
typedef long long ll;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
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
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}return x*b;
}
const int maxn=1e5+7,maxm=1e6+7;
int n,m,s;
const int inf=0x3f3f3f3f,inf2=0x7fffffff;
struct edge{
	int v,w,next;
}e[maxn];
int k=-1,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int dis[maxn],cnt[maxn];
queue<int>q;
bool spfa(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[x]=0;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(cnt[u]>=n)return 0;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;
				q.push(v);
			}
		}
	}return 1;
}
void init(){
	memset(head,-1,sizeof(head));
	n=readi(),m=readi(),s=readi();
	register int u,v,w;
	for(int i=1;i<=n;i++){
		u=readi(),v=readi(),w=readi();
		add(u,v,w);
		add(v,u,w);
	}
}
void solve(){
	if(!spfa(s));
	for(int i=1;i<=n;i++){
		if(dis[i]>=inf)printf("%d ",inf2);
		else printf("%d ",dis[i]);
	}
}
int main()
{
    init();
    solve();
    return 0;
}
