#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
using namespace std;
typedef long long ll;
#define Endl endl
inline int readi(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline int readl(){
	ll x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
const int maxn=1e5+7;
ll pt[maxn];//point，点值 
struct tree{
	int lt,rt;
	ll val,tag;
}ts[maxn<<2];
inline int nl(int x){
	return x<<1;
}
inline int nr(int x){
	return (x<<1)|1;
}
inline int cmid(int lt,int rt){
	return lt+(rt-lt>>1);
}
void pushup(int x){
	ts[x].val=ts[nl(x)].val+ts[nr(x)].val;
}
void pushdowm(int x){
	ll tag=ts[x].tag;
	if(!tag)return;
	int lt=nl(x),rt=nr(x);
	int lcnt=ts[lt].rt-ts[lt].lt+1;
	int rcnt=ts[rt].rt-ts[rt].lt+1;
	
	ts[lt].tag+=tag;
	ts[lt].val+=tag*lcnt;
	ts[rt].tag+=tag;
	ts[rt].val+=tag*rcnt;
	ts[x].tag=0;
}
void build(int x,int lt,int rt){
	ts[x].lt=lt;
	ts[x].rt=rt;
	if(lt==rt){
		ts[x].val=pt[lt];
		return; 
	}
	int mid=cmid(lt,rt);
	build(nl(x),lt,mid);
	build(nr(x),mid+1,rt);
	pushup(x);
}
int al=0,ar=0;
void adj(int lt,int rt){
	al=lt;
	ar=rt;
}
void update(int x,ll val){ 
	if(al<=ts[x].lt and ts[x].rt<=ar){
		int cnt=ts[x].rt-ts[x].lt+1;
		ts[x].tag+=val;
		ts[x].val+=val*cnt;
		return;
	}
	pushdowm(x);
	int mid=cmid(ts[x].lt,ts[x].rt);
	if(al<=mid)update(nl(x),val);
	if(ar>mid)update(nr(x),val);
	pushup(x);
}
ll ask(int x){
	if(al<=ts[x].lt and ts[x].rt<=ar)return ts[x].val;
	pushdowm(x);
	int mid=cmid(ts[x].lt,ts[x].rt);
	ll ans=0;
	if(al<=mid)ans+=ask(nl(x)); 
	if(ar>mid)ans+=ask(nr(x));
	return ans;
}

void build(int lt,int rt){
	build(1,lt,rt);
}
void update(ll val){
	update(1,val);
}
ll ask(){
	ask(1);
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
const int maxm=2e6+7;
struct edge{
	int v,w,next;
}e[maxm];
int head[maxn],k=0;
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}

int tot; 
int in[maxn],out[maxn];
void dfs(int u,int fa){
	in[u]=++tot;
	for(int i=head[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
	}
	out[u]=tot;
}

int n,m,r,mod;
int f[maxn];//点权 
void init(){
	memset(head,-1,sizeof(head));
	n=readi();m=readi();r=readi();mod=readi();
	for(int i=1;i<=n;i++){
		f[i]=readi();
	}
	for(int i=1;i<n;i++){
		int u=readi(),v=readi();
		add(u,v,0);
		add(v,u,0);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		pt[in[i]]=f[i];//将进入时间作为线段树应该处理的结点 
	}
	build(r,1,n);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int p;
void solve(){
	m=readi();
	for(int i=1,crt,x,y,z;i<=m;i++){
		crt=readi();
		if(crt==3){//子树结点全修改 
			x=readi();z=readi();
			adj(in[x],out[x]);
			update(r,z);
		}//用来线段树的只有in结点，没有out，所以就是经过多少个点就是多少个修改0 
		else if(crt==4){//子树求和 
			x=readi();
			adj(in[x],out[x]);
			ask(r);
		}
	}
}
int main()
{	
	init();
	solve();
	return 0; 
}
