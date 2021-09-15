#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1e6,maxm=1e6;
typedef long long ll;
struct edge{
	int v,w,next;
}e[maxm];
int k,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
int readi(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch)ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
//------------------------------------------
struct node{
	int fa,son,size,dep;//父节点，重儿子、子树大小,深度 
	ll val;
}p[maxn]; 
int jmp[maxn][30],lg[maxn];
void dfs(int u,int fa){//这个是用来处理回跳深度的 
	//p[u].dep=p[fa].dep+1;
	for(int i=1;i<=lg[p[u].dep];i++){
		jmp[u][i]=jmp[jmp[u][i-1]][i-1];
	}
	for(int i=head[u];i!=1;i=e[i].next){
		int v=e[i].v;
		if(v!=fa)dfs(v,u);
	}
}

int dfs2(int u,int fa){//这个是用来记录子树数量和父节点、重儿子 
	p[u].dep=p[fa].dep+1;
	p[u].fa=fa;
	p[u].size=1;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		p[u].size+=dfs2(v,u);
		if(p[v].size>p[p[u].son].size)p[u].son=v;
	}
	return p[u].size;
} 
struct link{
	int idx,top;
}l[maxn]; 
int tot,rk[maxn];
void dfs3(int u,int top){//记录头结点位置，以及dfs序和对应结点的双向记录 
	l[u].top=top;//记录他的重链头结点 
	l[u].idx=++tot;//记录他的dfs序位置 
	rk[tot]=u;//用新的dfs序位置找到u 
	
	if(!p[u].son)return;
	dfs(p[u].son,top);
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v!=p[u].son and v!=p[u].fa)dfs3(v,v);//由于是轻链，所以从这个开始重新找一条重链 
	}
} 
int sum(int x,int y){//获取一条子链上的权值和 
	
} 
int n,m,R,mod;
void init(){
	memset(head,-1,sizeof(head));
	for(int i=1;i<maxn;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
	n=readi();m=readi();R=readi();mod=readi();
	for(int i=1;i<=n;i++){
		p[i].val=readi();
	}
	for(int i=1,u,v;i<n;i++){
		u=readi();v=readi();
		add(u,v,0);
		add(v,u,0);
	}
	for(int i=1,crt,x,y,z;i<=m;i++){
		crt=readi();
		if(crt==1){
			
		}
		else if(crt==2){
			
		}
	}
}
void solve(){
	
}
int main()
{
    init();
    solve();
    return 0;
}
