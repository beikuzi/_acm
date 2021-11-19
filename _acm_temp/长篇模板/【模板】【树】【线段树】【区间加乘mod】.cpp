#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
#define nl(x) (x<<1)
#define nr(x) ((x<<1)|1)
#define mid(l,r) (l+(r-l>>1))
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
int n,m;
ll mod,pt[maxn];
struct tree{
	int l,r;
	ll m,a,v;
	void mul(ll k){m*=k,a*=k,v*=k;
	}
	void add(ll k){a+=k,v+=k*(r-l+1);
	}
	void mod(ll k){m%=k,v%=k,a%=k;
	}
	void set(int x,int y){l=x,r=y,m=1,a=0;
	}
	void reset(){a=0,m=1;
	}
	bool range(int x,int y){return x<=l and r<=y;
	}
}t[maxn<<2];
void pushup(int x){
	t[x].v=t[nl(x)].v+t[nr(x)].v;
	t[x].mod(mod);
}
void pushdown(int x){
	t[nl(x)].mul(t[x].m);
	t[nr(x)].mul(t[x].m);
	t[nl(x)].add(t[x].a);
	t[nr(x)].add(t[x].a);
	t[x].reset();
	t[nl(x)].mod(mod);
	t[nr(x)].mod(mod);
}
void build(int x,int l,int r){
	t[x].set(l,r);
	if(l==r){
		t[x].v=pt[l];
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
		t[x].mod(mod);
		return;
	}
	pushdown(x);
	int mid=mid(t[x].l,t[x].r);
	if(l<=mid)add(nl(x),l,r,k);
	if(r>mid) add(nr(x),l,r,k);
	pushup(x);
}
void mul(int x,int l,int r,ll k){
	if(t[x].range(l,r)){
		t[x].mul(k);
		t[x].mod(mod);
		return;
	}
	pushdown(x);
	int mid=mid(t[x].l,t[x].r);
	if(l<=mid)mul(nl(x),l,r,k);
	if(r>mid) mul(nr(x),l,r,k);
	pushup(x);
}
ll ask(int x,int l,int r){
	if(t[x].range(l,r))return t[x].v;
	pushdown(x);
	ll res=0;
	int mid=mid(t[x].l,t[x].r);
	if(l<=mid)res+=ask(nl(x),l,r);
	if(r>mid) res+=ask(nr(x),l,r);
	return res%mod;
}
void init(){
	n=readi(),m=readi(),mod=readl();
	for(int i=1;i<=n;i++){
		pt[i]=readl();
	}
	build(1,1,n);
}
void test(){
	for(int i=1;i<=n;i++){
		cout<<ask(1,i,i)<<endl;
	}
}
void solve(){
	for(int i=1;i<=m;i++){
		int z=readi(),l=readi(),r=readi();
		//cout<<z<<l<<r;
		switch(z){
			case 3:{
				printf("%lld\n",ask(1,l,r));
				break;
			}
			case 2:{
				add(1,l,r,readi());
				break;
			}
			case 1:{
				mul(1,l,r,readi());
				break;
			}
		}
		//test();
	}
}
int main()
{
    init();
    solve();
    return 0;
}
