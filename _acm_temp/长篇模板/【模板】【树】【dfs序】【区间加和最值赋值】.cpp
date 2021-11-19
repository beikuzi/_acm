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
#define inf 0x7fffffff
const int maxn=1e6+7;
int pt[maxn],val[maxn];
struct tree{
	struct node{
		int l,r;
		int v,mx;//总和、最值 
		int a,cov;//加法标记，覆盖标记 
		bool tag;//标记是否存在cov 
		void set(int x,int y){
			l=x,r=y;
			a=0;
			cov=tag=0;
			mx=-inf;
		}
		void set(){
			a=0;
			cov=tag=0;
		}
		void cover(int k){
			cov=mx=k;
			v=cov*(r-l+1);
			tag=1;
			a=0;
		}
		void add(int k){
			a+=k,mx+=k;
			v+=k*(r-l+1);
		}
		void change(int k){
			if(tag)cover(k+cov);//有tag就是覆盖 
			else add(k);//没有就是add，只能2选1 
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn<<2];
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
#define mid(x,y) (x+(y-x>>1))
	void pushup(int x){
		t[x].v=t[lt(x)].v+t[rt(x)].v;
		t[x].mx=max(t[lt(x)].mx,t[rt(x)].mx);
	}
	void pushdown(int x){
		if(t[x].tag){
			t[lt(x)].cover(t[x].cov);
			t[rt(x)].cover(t[x].cov);
		} 
		else{
			t[lt(x)].add(t[x].a);
			t[rt(x)].add(t[x].a); 
		} 
		t[x].set();
	}
	void build(int l,int r,int x=1){
		t[x].set(l,r);
		if(l==r){
			t[x].v=t[x].mx=pt[l];
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
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)mdf(l,r,k,lt(x));
		if(r>mid) mdf(l,r,k,rt(x));
		pushup(x);
	}
	void add(int l,int r,int k,int x=1){
		if(t[x].range(l,r)){
			t[x].change(k);
			return;
		}
		int mid=mid(t[x].l,t[x].r);
		pushdown(x);
		if(l<=mid)add(l,r,k,lt(x));
		if(r>mid) add(l,r,k,rt(x));
		pushup(x);
	}
	int ask_sum(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		pushdown(x);
		int res=0;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res+=ask_sum(l,r,lt(x));
		if(r>mid) res+=ask_sum(l,r,rt(x));
		return res;
	}
	int ask_mx(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].mx;
		}
		pushdown(x);
		int res1=-inf,res2=-inf;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res1=ask_mx(l,r,lt(x));
		if(r>mid) res2=ask_mx(l,r,rt(x));
		return max(res1,res2);
	}
	void test(int n){
		for(int i=1;i<=n;i++){
			cout<<ask_sum(1,i)<<' ';
		}cout<<endl;
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
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(v==f)continue;
			dfs_rl(v,u);
			cnt[u]+=cnt[v];
			if(cnt[v]>cnt[son[u]])son[u]=v;
		}
	}
	int tot;
	int rnk[maxn],dfn[maxn],top[maxn];
	void dfs_od(int u,int ftop){
		dfn[u]=++tot;
		rnk[tot]=u;
		top[u]=ftop;
		
		if(!son[u])return;
		dfs_od(son[u],ftop);
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(v!=fa[u] and v!=son[u])dfs_od(v,v);
		}
	}
	void init(int st){
		dfs_rl(st,0);
		dfs_od(st,st);
		for(int i=1;i<=tot;i++){
			pt[i]=val[rnk[i]];
		}
		t.build(1,tot);
	}
	int lca(int x,int y){
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
			x=fa[fx];
			fx=top[x];
		}
		return (dep[x]<dep[y])?x:y;
	}
	//链上操作
	void mdf(int x,int y,int k){//链上点权修改 
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
			t.mdf(dfn[fx],dfn[x],k);
			x=fa[fx];
			fx=top[x];
		}
		if(dep[x]<dep[y])swap(x,y);
		t.mdf(dfn[y],dfn[x],k);
	} 
	void add(int x,int y,int k){
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
			t.add(dfn[fx],dfn[x],k);
			x=fa[fx],fx=top[x];
		}
		if(dep[x]<dep[y])swap(x,y);
		t.add(dfn[y],dfn[x],k);
	}
	int ask_sum(int x,int y){
		int res=0;
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			cout<<x<<' '<<res <<endl;
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
			res+=t.ask_sum(dfn[fx],dfn[x]);
			x=fa[fx],fx=top[x];
		}
		if(dep[x]<dep[y])swap(x,y);
		return res+t.ask_sum(dfn[y],dfn[x]);
		 
	}
	int ask_mx(int x,int y){
		int res=-inf;
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
			res=max(res,t.ask_mx(dfn[fx],dfn[x]));
			x=fa[fx],fx=top[x];
		}
		if(dep[x]<dep[y])swap(x,y);
		return res=max(res,t.ask_mx(dfn[y],dfn[x]));
	}
	//子树操作 
	void add(int x,int k){
		t.add(dfn[x],dfn[x]+cnt[x]-1,k);
	} 
	void mdf(int x,int k){
		t.mdf(dfn[x],dfn[x]+cnt[x]-1,k);
	}
	int ask_sum(int x){
		return t.ask_sum(dfn[x],dfn[x]+cnt[x]-1);
	}
	int ask_mx(int x){
		return t.ask_mx(dfn[x],dfn[x]+cnt[x]-1);
	}
	//
	void test(int n){
		//t.test(n);		
		for(int i=1;i<=n;i++){
			cout<<ask_mx(i,i)<<' ';
		}cout<<endl;
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
/*
1.子树修改
2.子树加
3.树链修改
4.树链加
5.子树和 
6.子树最值 
7.树链和
8.树链最值 

5
1 2
1 3
3 4
3 5
10
1 1 1919810
2 1 114514
3 2 4 6
4 2 5 8
5 1
6 1
7 1 4
8 1 4

test
	1919810*5
	2034324*5
	6 6 6 6 2034324
	14 14 14 6 2034332
	同上 
	同
	同 
	同 
ans 
	2034380
	2034332
	34
	14
*/
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
    			int res=at.ask_sum(x,x);
    			printf("%d\n",res);
    			break;
    		}
    	}
    	//at.test(n);
    }
    return 0;
}
