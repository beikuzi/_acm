#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;//区间修改，区间查询 
const int maxn=1e6+7;
typedef long long ll;
int lowbit(int x){
	return x&-x;
} 
int n,m;
ll pt[maxn]; 
struct op{
	struct tree{
		ll d,f;
	}t[maxn];
	void read(int x,ll dv){
		t[x].d=dv;
		t[x].f=dv*x;
		for(int i=1;i<lowbit(x);i<<=1){
			t[x].d+=t[x-i].d;
			t[x].f+=t[x-i].f;
		}
	}
	void add(int l,int r,ll dv){//区间增减 
		for(int i=l;i<=n;i+=lowbit(i)){
			t[i].d+=dv;
			t[i].f+=dv*l;
		}
		for(int i=r+1;i<=n;i+=lowbit(i)){
			t[i].d-=dv;
			t[i].f-=dv*(r+1);
		}
	}
	ll ask(int x){//单点前缀和 
		ll res=0;
		for(int i=x;i;i-=lowbit(i)){
			res+=(x+1)*t[i].d-t[i].f;
		}return res;
	}
	ll ask(int l,int r){//区间查询 
		return ask(r)-ask(l-1);
	}
	void change(int x,ll val){//单点修改 
		ll dv=val-ask(x,x);
		add(x,x,dv);
	} 
}o;
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
//-------------------------------------------------------
void init(){
	n=readi(),m=readi();
	for(int i=1;i<=n;i++){
		pt[i]=readl();
		o.read(i,pt[i]-pt[i-1]);
	}
}
void solve(){
	register int z;
	register ll x,y,k;
	for(int i=1;i<=m;i++){
		//for(int i=1;i<=n;i++)printf("%lld\n",o.ask(i));cout<<endl;
		z=readi();
		if(z==1){
			x=readi(),y=readi(),k=readl();
			o.add(x,y,k);
		}
		else if(z==2){
			x=readi(),k=readl();
			o.change(x,k);
		} 
		else {
			x=readi(),y=readi();
			printf("%lld\n",o.ask(x,y));
		}
	}
}
int main(){
	init();
	solve();
	return 0;
}
