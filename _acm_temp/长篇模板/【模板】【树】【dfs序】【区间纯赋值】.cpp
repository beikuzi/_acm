#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x*b;
}
const int maxn=1e6+7;
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
#define mid(x,y) (x+(y-x>>1))
int pt[maxn];
struct tree{
	struct node{
		int v,cov;
		int l,r;
		bool tag;
		void set(int x,int y){
			l=x,r=y;
			cov=tag=0;
		}
		void set(){
			cov=tag=0;
		}
		void cover(int k){
			cov=k;
			v=cov*(r-l+1);
			tag=1;
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn<<2];
	void pushup(int x){
		t[x].v=t[lt(x)].v+t[rt(x)].v;
	}
	void pushdown(int x){
		if(t[x].tag){
			t[lt(x)].cover(t[x].cov);
			t[rt(x)].cover(t[x].cov);			
		}
		t[x].set();
	}
	void build(int l,int r,int x=1){
		t[x].set(l,r);
		if(l==r){
			t[x].v=pt[l];
			return;
		}
		int mid=mid(l,r);
		build(l,mid,lt(x));
		build(mid+1,r,rt(x));
		pushup(x);
	}
	void mdf(int l,int r,int k,int x=1){
		if(t[x].range(l,r)){
			t[x].cover(k);
			return;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		if(l<=mid)mdf(l,r,k,lt(x));
		if(r>mid) mdf(l,r,k,rt(x));
		pushup(x);
	}
	int ask(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		int res=0;
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		if(l<=mid)res+=ask(l,r,lt(x));
		if(r>mid) res+=ask(l,r,rt(x));
		return res;
	}
	void test(int n){
		for(int i=1;i<=n;i++){
			cout<<ask(i,i)<<endl;
		}
	}
};
struct edge{
	int v,w,next;
}e[maxn<<1];
int k=-1,head[maxn];
void add(int u,int v,int w){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v,e[k].w=w;
}
struct dfs_tree{
	tree t;
	int dep[maxn];
	int fa[maxn],son[maxn],cnt[maxn];
	void dfs_rl(int u,int f){
		fa[u]=f;
		dep[u]=dep[f]+1;
		cnt[u]=1;
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v;
			if(v==f)continue;
			dfs_rl(v,u);
			cnt[u]+=cnt[v];
			if(cnt[v]>cnt[son[u]])son[u]=v;
		}
	}
	int tot;
	int dfn[maxn],rnk[maxn],top[maxn];
	void dfs_od(int u,int ftop){
		dfn[u]=++tot;
		rnk[tot]=u;
		top[u]=ftop;
		
		if(!son[u])return;
		dfs_od(son[u],ftop);
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v;
			if(v!=fa[u] and v!=son[u])dfs_od(v,v);
		}
	}
	void mdf(int x,int y,int k){
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(fx,fy),swap(x,y);
			t.mdf(dfn[fx],dfn[x],k);
			x=fa[fx],fx=top[x];
		}
		if(dep[x]<dep[y])swap(x,y);
		t.mdf(dfn[y],dfn[x],k);
	}
	int ask(int x,int y){
		int fx=top[x],fy=top[y];
		int res=0;
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
			res+=t.ask(dfn[fx],dfn[x],k);
			x=fa[fx],fx=top[x];
		}
		if(dep[x]<dep[y])swap(x,y);
		return res+t.ask(dfn[y],dfn[x]);
	}
	void mdf(int x,int k){
		t.mdf(dfn[x],dfn[x]+cnt[x]-1,k);
	}
	int ask(int x){
		return t.ask(dfn[x],dfn[x]+cnt[x]-1);
	}
	void init(int st){
		dfs_rl(st,0);
		dfs_od(st,st);
		for(int i=1;i<=tot;i++){
			pt[i]=0;
		}
		t.build(1,tot);
		//t.test(tot); 
	}
}at;
int n,m;
void init(){
	memset(head,-1,sizeof(head));
	n=readi();
	for(int i=1;i<n;i++){
		int u=readi(),v=readi();
		add(u,v,0);
		add(v,u,0);
	}
	at.init(1);
	
}
int main()
{
    init();
    m=readi();
	for(int i=1;i<=m;i++){
		int op=readi();
		int x=readi();
		switch(op){
			
			case 1:{
				at.mdf(x,1);
				break;
			}
			case 2:{
				at.mdf(1,x,0);
				break;
			}
			case 3:{
				int res=at.ask(x,x);
				printf("%d\n",res);
				break;
			}
			
		}
		//at.t.test(n);
	}
    return 0;
}
