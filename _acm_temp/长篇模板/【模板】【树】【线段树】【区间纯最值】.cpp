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
typedef long long ll;
inline ll readl(){
	ll x=0,b=1;
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
ll pt[maxn];
struct tree{
	struct node{
		int l,r;
		ll a,v;
		void set(int x,int y){
			l=x,r=y,a=0;
		}
		void set(){
			a=0;
		}
		void add(ll k){
			a+=k,v+=k;
		}
		bool range(int x,int y){
			return x<=l and r<=y;
		}
	}t[maxn<<2];
#define lt(x) (x<<1)
#define rt(x) ((x<<1)|1)
#define mid(l,r) (l+(r-l>>1))
	void pushup(int x){
		t[x].v=max(t[lt(x)].v,t[rt(x)].v);
	}
	void pushdown(int x){
		t[lt(x)].add(t[x].a);
		t[rt(x)].add(t[x].a);
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
	void add(int l,int r,ll k,int x=1){
		if(t[x].range(l,r)){
			t[x].add(k);
			return;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)add(l,r,k,lt(x));
		if(r>mid) add(l,r,k,rt(x));
		pushup(x);
	}
#define inf 0x7fffffff
	ll ask(int l,int r,int x=1){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		ll res1=-inf,res2=-inf;
		if(l<=mid)res1=ask(l,r,lt(x));
		if(r>mid) res2=ask(l,r,rt(x));
		return max(res1,res2);
	}
	void test(int n){
		for(int i=1;i<=n;i++){
			cout<<ask(i,i)<<endl;
		}
	}
}mt; 
int n,m;
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readl();
	}
	mt.build(1,n);
}
int main()
{
    init();
    for(int i=1;i<=m;i++){
    	int op=readi();
    	int x=readi(),y=readi();
    	switch(op){
    		case 1:{
    			ll res=mt.ask(x,y);
    			printf("%lld\n",res);
    			break;
    		}
    		case 2:{
    			mt.add(x,y,readl());
    			break;
    		}
    	}
    }
    return 0;
}
