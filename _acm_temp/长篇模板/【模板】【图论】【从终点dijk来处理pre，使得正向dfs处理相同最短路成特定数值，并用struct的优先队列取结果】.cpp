#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int cmax,n,ed,m;
//车站上限，车站总数，目标车站，边数 
typedef long long ll;
typedef pair<int,int>pii;
#define M make_pair
priority_queue<pii,vector<pii>,greater<pii> >q;
const int maxn=1e3+7,maxm=1e5+7;
//要求有最短路就优先走最短路
//只要经过不够的点就要补充，经过过多的点可以往后送，最后回收 
//最短路相同，走送出去车最少的路
//送出去车最少的路相同，选收回来车最少的路 
struct edge{
	int v,w,next;
}e[maxm];
int k=-1,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
int pt[maxn];
void init(){
	memset(head,-1,sizeof(head));
	cmax=readi(),n=readi(),ed=readi(),m=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi()-cmax/2;
	}
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=readi(),v=readi(),w=readi();
		add(u,v,w);
		add(v,u,w);
	}
}
vector<int>pre[maxn];
int dis[maxn],vis[maxn];
void dijk(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(M(0,x));
	dis[x]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w==dis[v]){
				pre[v].push_back(u);
			}
			else if(dis[u]+w<dis[v]){
				pre[v].clear();
				pre[v].push_back(u);
				q.push(M(dis[v]=dis[u]+w,v));
			}
		}
	}
}
//用dfs把一条路上所有的 
struct result{
	int k,in,out;//in回收，out发出 
	vector<int>ph;
	friend bool operator<(const result &x,const result &y){
		if(x.out==y.out)return x.in>y.in;
		return x.out>y.out;
	}
};
priority_queue<result>p;
void print(){
	result res=p.top();
	printf("%d ",res.out);
	int cnt=res.ph.size();
	for(int i=0;i<cnt;i++){
		printf("%d->",res.ph[i]);
	}
	printf("%d %d",ed,res.in);//收回来的情况 
}
void dfs(int u,int in,int out,vector<int>vct){
	int cnt=pre[u].size();
	in+=pt[u];
	if(in<0){
		out-=in;
		in=0;
	}
	if(cnt==0 and u==ed){
		result res;
		res.k=k;
		res.in=in;
		res.out=out;
		res.ph=vct;
		p.push(res);
		return;
	}
	vct.push_back(u);
	for(int i=0;i<cnt;i++){
		dfs(pre[u][i],in,out,vct);
	}
}
void solve(){
	dijk(ed);
	vector<int>temp;
	dfs(0,0,0,temp);
	print();
} 
int main()
{
    init();
    solve();
    return 0;
}
