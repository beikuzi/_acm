#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
const int maxn=1e4+7,maxm=1e5+7;
struct edge{
	int v,next;
}e[maxm];
int k=-1;
int head[maxn];
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
}
stack<int>s;
int low[maxn],dfn[maxn],vis[maxn];
int col[maxn],cnt[maxn];
int tot,mtot;
int n,m;
//1.有效深搜low[v]
//2.有效当次成环dfn[v]
//3.取出来 
void tarj(int u){
	low[u]=dfn[u]=++tot;//tot，深度，每个tarj给一个点赋深度 
	s.push(u);vis[u]=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){//当找到环的时候才会形成dfn[v]==true，这本质是一种深搜 
			tarj(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){//这个点连上了这次找到的环 ，如果是之前找到的那么没有vis 
			low[u]=min(low[u],dfn[v]);
		}
	}
	int tab;
	if(low[u]==dfn[u]){//这个点形成的环，由这个点开始取一次就可以了 
		//如果搜到了以前搜过的dfn，就会导致dow变化，搜索序与实际序不一样，就不会压入了
		//孤立的一个点也会被看做强连通 
		mtot++;//染色种类数
		do{
			tab=s.top();
			s.pop();
			vis[tab]=0;
			col[tab]=mtot;
			cnt[mtot]++;
		}while(tab!=u);
	}
}
void init(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
} 
int in[maxn],out[maxn];
void get_deg(){
	for(int u=1;u<=n;u++){
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(col[u]!=col[v]){//u和v相连，但是不是同色
				in[col[v]]++;
				out[col[u]]++; 
			}
		}
	}
}
//case1:	全部都得到，需要进入强连通的数量  ： 0入度的数量 
//case2:	扩充出度，使得整体变成强连通  ： 0出度的数量
//case3:	最小操作边，使得图强连通： max(0入度，0出度） 
int find_out(){//寻找唯一0出度的点 
	int time=0;
	for(int i=1;i<=mtot;i++){
		if(out[i]==0){
			if(time)return -1;
			time=i;
		}
	}
	return time;
}
bool vis2[maxn];
void solve(){
	for(int i=1;i<=n;i++){
    	if(vis2[i])continue;
    	int cl=col[i];
    	for(int j=i;j<=n;j++){
    		if(vis2[j])continue;
    		if(col[j]==cl){
    			printf("%d ",j);
    			vis2[j]=true;
    		}
    	}
    	printf("\n");
    }
}
int main()
{
    init();
    for(int i=1;i<=n;i++){
    	if(!dfn[i])tarj(i);
    }
    get_deg();
    int ans=find_out();
    return 0;
    
}
