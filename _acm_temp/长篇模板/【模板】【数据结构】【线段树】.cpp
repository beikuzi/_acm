#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring> 
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
#define nl(x) (x<<1)
#define nr(x) ((x<<1)|1)
#define mid(l,r) (l+(r-l>>1))
ll pt[maxn];
int n,m;
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
struct tree{
	int l,r;
	ll v,a;
	void add(ll k){
		a+=k;
		v+=k*(r-l+1);
	}
	void reset(){
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
}
void pushdown(int x){
	t[nl(x)].add(t[x].a);
	t[nr(x)].add(t[x].a);
	t[x].reset();
}
void build(int x,int l,int r){
	t[x].set(l,r);
	if(l==r){
		t[x].v=pt[l];
		return ;
	}
	int mid=mid(l,r);
	build(nl(x),l,mid);
	build(nr(x),mid+1,r);
	pushup(x);
}
void add(int x,int l,int r,ll k){
	if(t[x].range(l,r)){
		t[x].add(k);
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
		return t[x].v;
	}
	pushdown(x);
	ll res=0;
	int mid=mid(t[x].l,t[x].r);
	if(l<=mid)res+=ask(nl(x),l,r);
	if(r>mid) res+=ask(nr(x),l,r);
	return res;
}
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++)pt[i]=readl();
	build(1,1,n);
}
void solve(){
	register int z,x,y;
	for(int i=1;i<=m;i++){
		z=readi(),x=readi(),y=readi();
		switch(z){
			case 1:{
				add(1,x,y,readl());
				break;
			}
			case 2:{
				printf("%lld\n",ask(1,x,y));
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
