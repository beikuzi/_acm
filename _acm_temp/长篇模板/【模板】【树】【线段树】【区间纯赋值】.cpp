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
}t; 
int n,m;
void init(){
	n=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readi();
	}t.build(1,n);
	m=readi();
	for(int i=1;i<=m;i++){
		
	}
}
int main()
{
    init();
    return 0;
}
