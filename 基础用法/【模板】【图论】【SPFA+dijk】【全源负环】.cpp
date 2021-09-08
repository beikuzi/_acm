#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1e5,maxm=1e5;
const int inf=1e9;
typedef long long ll;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn],vis[maxn],amo,cnt[maxn];
ll dis[maxn],d[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	e[k].v=v,e[k].w=w;
	head[u]=k;
}

int n,m;
//用节点0连所有其他点，求出到其他点的最短路，记做d[i]
//因为只有负数边，才会导致最短路更新，这样让负权边直接边正 
//然后将路上边权修改为w+d[u]-d[v] 
queue<int>q;
bool spfa(int x){
	memset(d,0x3f,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	d[x]=0;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		//if(cnt[u]>=n)return 1;
		if(cnt[u]>n)return 1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				cnt[v]=cnt[u]+1;
				q.push(v);
			}
		}
	}
	return 0;
}

#define M(x,y) make_pair(x,y)
typedef pair<ll,ll> pii;
priority_queue<pii,vector<pii>,greater<pii> >p;

ll ans;
void emp(){
	priority_queue<pii,vector<pii>,greater<pii> >empty;
	swap(empty,p);
}
void dijk(int x){
	emp();
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	amo=0;
	p.push(M(0,x));
	//while(!p.empty() and amo<n){
	while(!p.empty() and amo<=n){
		int d=p.top().first,u=p.top().second;
		p.pop();
		if(vis[u])continue;vis[u]|=1;
		amo++;
		for(int i=head[u];i;i=e[i].next){
			ll v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				p.push(M(dis[v],v));
			}
		}
	}
}
int main()
{
    
    scanf("%d%d",&n,&m);
    int u,v,w;
    memset(head,0,sizeof(head));
    
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&u,&v,&w);
    	add(u,v,w);
    }
    for(int i=1;i<=n;i++)add(0,i,0); 
    if(spfa(0)){
    	printf("-1");
    	return 0;
    }
    //for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<endl;
    for(int j=1;j<=n;j++){
    	for(int i=head[j];i;i=e[i].next){//
    		e[i].w+=d[j]-d[e[i].v];//对应的边 每个都增加u-v 
    	}
    }
    ll res;
    for(int i=1;i<=n;i++){
    	res=0;
    	dijk(i);
    	for(int j=1;j<=n;j++){
    		//cout<<dis[j]+d[j]-d[i]<<' ';
    		if(dis[j]==0x3f3f3f3f3f3f3f3f){
    			dis[j]=1e9;
    		}
    		else dis[j]+=d[j]-d[i];
    		res+=(ll)j*dis[j];
    	}
    	//cout<<endl;
    	printf("%lld\n",res);
    }
}
