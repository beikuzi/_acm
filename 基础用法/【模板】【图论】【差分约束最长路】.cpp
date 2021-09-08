#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=1e5+7,maxm=maxn*3;
const int inf=1e8;
int cnt[maxn],dis[maxn],head[maxn];
int k;
queue<int>q;
struct edge{
	int v,w,next;
}e[maxm];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
//由于原来的图可能不是完全连通的，跑最短路并且反向取正时，取得不是局部最负值而是全局最负值，所以原理上出错…… 
//如果TLE，可以把超级原点的读入，其他边的读入方式改变成倒序
//(玄学优化，因为spfa和djik用于点多边少的环节，而有些部分可能特别连通性特别强，而且还是等价值，导致在那部分反复入队特别多 
//注意：添加超级源点也需要边， 所以要开原来的3倍 
bool spfa(int x){
	memset(cnt,0,sizeof(cnt));
	//memset(dis,0,sizeof(dis));
	//for(int i=1;i<=n;i++)dis[i]=1; 
	q.push(x);dis[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(cnt[u]>n+1)return true;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]<dis[u]+w){
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
	memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i=1;i<=m;i++){
    	scanf("%d%d%d",&w,&u,&v);
    	//最短路，写成v<=u+w	压入u，v，w
		//最长路，写成v>=u+w		压入u，v，w 
    	if(w==1){
    		add(u,v,0);
    		add(v,u,0);
    	}
    	else if(w==2){
    		add(u,v,1);
    		if(u==v){
    			cout<<-1;return 0;
    		}
    	}
    	else if(w==3)add(v,u,0);
    	else if(w==4){
    		add(v,u,1);
    		if(v==u){
    			cout<<-1;return 0;
    		}
    	}
    	else if(w==5)add(u,v,0);
	}
    for(int i=n;i>=1;i--){
    	add(0,i,0);
    }
	if(spfa(0)){
		cout<<-1;
		return 0;
	}
    ll ans=0;	
    for(int i=1;i<=n;i++){
    	ans+=dis[i];
    }
    printf("%lld",ans);
    return 0;
}
