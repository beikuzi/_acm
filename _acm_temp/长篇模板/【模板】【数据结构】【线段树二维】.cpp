#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<new>
#include<cstring> 
using namespace std;
const int maxn=1e5+7;
//typedef long long ll;
#define ll int
#define nl(x) (x<<1)
#define nr(x) ((x<<1)|1)
#define mid(l,r) (l+(r-l>>1))
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
struct tree_2{
	ll *pt;
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
	tree_2(){
		pt=new ll[maxn]();
	}
	
	void pushup(int x){
		t[x].v=t[nl(x)].v+t[nr(x)].v;
	}
	void pushdown(int x){
		t[nl(x)].add(t[x].a);
		t[nr(x)].add(t[x].a);
		t[x].reset();
	}
	void bd(int x,int l,int r){
		t[x].set(l,r);
		if(l==r){
			t[x].v=pt[l];
			return ;
		}
		int mid=mid(l,r);
		bd(nl(x),l,mid);
		bd(nr(x),mid+1,r);
		pushup(x);
	}
	void build(int l,int r){
		bd(1,l,r);
		delete []pt;
	}
	void ad(int x,int l,int r,ll k){
		if(t[x].range(l,r)){
			t[x].add(k);
			return;
		}
		pushdown(x);
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)ad(nl(x),l,r,k);
		if(r>mid) ad(nr(x),l,r,k);
		pushup(x);
	}
	void add(int l,int r,ll k){
		ad(1,l,r,k);
	}
	ll ak(int x,int l,int r){
		if(t[x].range(l,r)){
			return t[x].v;
		}
		pushdown(x);
		ll res=0;
		int mid=mid(t[x].l,t[x].r);
		if(l<=mid)res+=ak(nl(x),l,r);
		if(r>mid) res+=ak(nr(x),l,r);
		return res;
	}
	ll ask(int l,int r){
		return ak(1,l,r);
	}
}tr[30]; 
string s;
void init(){
	getline(cin,s);
	m=readi();
	n=s.length();
	for(int i=0;i<n;i++){
		int loc=s[i]-96;
		tr[loc].pt[i+1]=1;
	}
	for(int i=1;i<=26;i++){
		tr[i].build(1,n);
	}
}
void solve(){
	int z,x,y;
	char ch;
	for(int i=1;i<=m;i++){
		z=readi();
		if(z==2){
			x=readi(),y=readi();
			int res=0;
			for(int i=1;i<=26;i++){
				if(tr[i].ask(x,y)>0)res++;
			}
			printf("%d\n",res);
		}
		else{
			x=readi();//
			y=getchar()-96; //现在对应的树 
			z=s[x-1]-96;//原来对应的树 
			s[x-1]=y+96;
			tr[y].add(x,x,1);
			tr[z].add(x,x,-1);
		}
	}
}
int main()
{
    init();
    solve();
    return 0;
}
