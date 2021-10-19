#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1e5+7,maxm=1e5+7;
typedef long long ll;
typedef pair<int,int>pii;
#define M make_pair
priority_queue<pii,vector<pii>,greater<pii> >q;
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
int k=-1,head[maxn];
struct edge{
	int v,next;
}e[maxm<<1];
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}
int f[maxn];
int fid(int x){
	return (x==f[x])?f[x]:f[x]=fid(f[x]);
}
struct node{
	int x,val;
}d[maxn]; 
bool cmp(node a,node b){
	return a.val<b.val;
}
vector<int>g[maxn];
//------------------------------------------------------- 
int n;
//存无向边 
//用并查集
//记录结点的值，并且按点权来sort点 
int dep[maxn];
void init(){
	k=-1;
	n=readi();
	for(int i=1;i<=n;i++){
		dep[i]=f[i]=0;//由于单次数量不多，可以这样init
		head[i]=-1;
		g[i].clear();
	}
	
	register int u,v;
	for(int i=1;i<n;i++){
		u=readi(),v=readi();
		//add(u,v);
		//add(v,u);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		d[i].x=i,d[i].val=readi();
	}
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
	}
}

void solve(){
	sort(d+1,d+1+n,cmp);
	//重新造一个连通图出来，可以考虑vector存边，struct重构，再拿来跑 
	for(int i=1;i<=n;i++){
		int u=d[i].x;
		f[u]=u;
		int m=g[u].size();
		for(int j=0;j<m;j++){
			int v=g[u][j];
			if(f[v]){
				v=fid(v);
				f[v]=u;
				add(u,v);
				add(v,u);
			}
		}
	}
	dfs(d[n].x,-1);
	for(int i=1;i<=n;i++){
		printf("%d\n",dep[i]);
	}
}
int main()
{
    int t=readi();
    while(t--){
    	init();
    	solve(); 
    }return 0;
}
