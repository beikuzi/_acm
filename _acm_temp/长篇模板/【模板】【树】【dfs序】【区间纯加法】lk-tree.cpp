#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
inline int readi(){
	int x=0;
	char ch=getchar();
	while('0'>ch or ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
} 
inline ll readl(){
	ll x=0;
	char ch=getchar();
	while('0'>ch or ch>'9')ch=getchar();
	while('0'<=ch and ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
const int maxn=1e5+7;
struct edge{
	int v,next;
}e[maxn<<1];
int k=-1,head[maxn];
void add(int u,int v){
	e[++k].next=head[u];
	head[u]=k;
	e[k].v=v;
} 
int val[maxn],mod;
#define nl(x) (x<<1)
#define nr(x) ((x<<1)|1)
#define mid(l,r) (l+(r-l>>1))
struct tree{
	ll pt[maxn];
	struct tr{
		int l,r;
		ll a,v;
		void add(ll k){
			a+=k;
			v+=k*(r-l+1);//�������ֵ,v+=k,����ask��add������min��max 
		}
		void md(){
			a%=mod,v%=mod;
		}
		void set(){
			a=0;
		}
		void set(int x,int y){
			l=x,r=y,a=0;
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn<<2];
	void pushup(int x){
		t[x].v=t[nl(x)].v+t[nr(x)].v;
		t[x].md();
	}
	void pushdown(int x){
		t[nl(x)].add(t[x].a);
		t[nr(x)].add(t[x].a);
		t[x].set();
		t[nl(x)].md();
		t[nr(x)].md();
	}
	void build(int x,int l,int r){
		t[x].set(l,r);
		if(l==r){
			t[x].v=pt[l];
			t[x].md();
			return;
		}
		int mid=mid(l,r);
		build(nl(x),l,mid);
		build(nr(x),mid+1,r);
		pushup(x);
	}
	void add(int x,int l,int r,ll k){
		if(t[x].range(l,r)){
			t[x].add(k);
			t[x].md();
			return;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)add(nl(x),l,r,k);
		if(r>mid) add(nr(x),l,r,k);
		pushup(x);
	}
	ll ask(int x,int l,int r){
		if(t[x].range(l,r)){
			return t[x].v%mod;
		}
		pushdown(x);
		ll res=0;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res+=ask(nl(x),l,r);
		if(r>mid) res+=ask(nr(x),l,r);
		return res%mod;
	}
	void build(int l,int r){build(1,l,r);	}
	void add(int l,int r,ll k){add(1,l,r,k);	}
	ll ask(int l,int r){return ask(1,l,r);	}
};

struct LK_tree{
	tree t;
	int dep[maxn];
	int fa[maxn],son[maxn],cnt[maxn];//son:�ض��ӣ�cnt:�����Ĵ�С 
	void dfs_relay(int u,int f){//�������ڵ㡢�ӽ�㡢�ض��ӽ�� 
		dep[u]=dep[f]+1;
		fa[u]=f;
		cnt[u]=1;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(v==f)continue;
			dfs_relay(v,u);
			cnt[u]+=cnt[v];
			if(cnt[v]>cnt[son[u]])son[u]=v;
		}
	}
	int dfn[maxn],top[maxn],rnk[maxn];//dfs���ͷ��㣬rnk�µ����Ӧ��ԭ�� 
	int tot=0;
	void dfs_order(int u,int ftop){//��ǰ�ڵ�͸��ڵ�һֱ���ϵ�ͷ��� 
		dfn[u]=++tot;
		rnk[tot]=u;
		top[u]=ftop;
		
		if(!son[u])return;
		dfs_order(son[u],ftop);//���ȶ��ض��ӽ������� 
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(v!=fa[u] and v!=son[u])dfs_order(v,v);//���ض���ֱ�Ӷ��˾������Լ� 
		}
	} 
	int lca(int x,int y){
		int fx=top[x],fy=top[y];
		while(fx!=fy){
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);//ѡ����ȸ�����Ǹ������� 
			x=fa[fx];
			fx=top[x];//ֱ���������� 
		}return (dep[x]<dep[y])?x:y;
	}
	void init(int st){
		dfs_relay(st,0);//�������µ�ָ�� 
		dfs_order(st,st);//����dfs�� 
		for(int i=1;i<=tot;i++){
			t.pt[i]=val[rnk[i]];//��������Ķ�Ӧ����ֵ 
		}
		t.build(1,tot);
	}
	//���ϵ�Ȩ�� 
	void add(int x,int y,ll k){
		int fx=top[x],fy=top[y];
		while(fx!=fy){//�����㲻��һ������ 
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);//ѡ����ȸ�����Ǹ������� 
			t.add(dfn[fx],dfn[x],k);
			x=fa[fx],fx=top[x];//�������ϴ��� 
		}
		if(dep[x]>dep[y])swap(x,y);//�Ѿ�ӵ�й�ͬ�ĸ��ڵ㣬��x��ΪС����һ�� 
		t.add(dfn[x],dfn[y],k);
	}  
	ll ask(int x,int y){
		ll ans=0;
		int fx=top[x],fy=top[y];
		while(fx!=fy){//�����㲻��һ������ 
			if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);//ѡ����ȸ�����Ǹ������� 
			ans=(ans+t.ask(dfn[fx],dfn[x]))%mod;
			x=fa[fx],fx=top[x];//�������ϴ��� 
		}
		if(dep[x]>dep[y])swap(x,y);
		return (ans+t.ask(dfn[x],dfn[y]))%mod;
	}
	//����������Ȩ��
	void add(int x,ll k){
		t.add(dfn[x],dfn[x]+cnt[x]-1,k);
	} 
	ll ask(int x){
		return t.ask(dfn[x],dfn[x]+cnt[x]-1);//ͨ������С����ȡ������Ȩ�� 
	} 
}tr;

int n,m,st;
void init(){
	memset(head,-1,sizeof(head));
	n=readi(),m=readi();st=readi();mod=readl();
	for(int i=1;i<=n;i++){
		val[i]=readl();
	}
	for(int i=1;i<n;i++){
		int u=readi(),v=readi();
		add(u,v);
		add(v,u);
	}
	tr.init(st);
}
void solve(){	
	for(int i=1;i<=m;i++){
		int op=readi();
		switch(op){
			int x,y;
			ll val;
			case 1:{
				x=readi(),y=readi(),val=readl();
				tr.add(x,y,val);
				break;
			}
			case 2:{
				x=readi(),y=readi();
				printf("%lld\n",tr.ask(x,y));
				break;
			}
			case 3:{
				x=readi(),val=readl();
				tr.add(x,val);
				break;
			}
			case 4:{
				x=readi();
				printf("%lld\n",tr.ask(x));
				break;
			}
		}
	}
}
int main()
{
    init();
    solve();
    return 0;
}
